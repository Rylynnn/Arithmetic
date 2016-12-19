#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cmath>
#define INF 0x3f3f3f3f
#define MAX 207
#define eps 1e-8
using namespace std;
struct node{
    int l,r;
    int c;
    double len,rl,rr;
}seg[MAX*3];
struct line{
    double h,x1,x2;//当前线段的高度，和与x轴平行的两个端点坐标
    int cnt;//表示是上边（-1）还是下边（1）
    bool operator < (const line &b)const{
        return h<b.h;
    }
}l[MAX];
double x[MAX];
void build(int l,int r,int t){
    seg[t].l=l;
    seg[t].r=r;
    seg[t].len=seg[t].c=0;
    seg[t].rl=x[l];
    seg[t].rr=x[r];
    if(l+1==r){
        return;
    }
    int mid;
    mid=(l+r)>>1;
    build(l,mid,t<<1);
    build(mid,r,t<<1|1);
}
void push_up(int t){
    if(seg[t].c>0){
        seg[t].len=seg[t].rr-seg[t].rl;
        return;
    }
    if(seg[t].l+1==seg[t].r){
        seg[t].len=0;
    }
    else{
        seg[t].len=seg[t<<1].len+seg[t<<1|1].len;
    }
}
void update(int t,line now){
    if(fabs(seg[t].rl-now.x1)<eps&&fabs(seg[t].rr-now.x2)<eps){
        seg[t].c+=now.cnt;
        push_up(t);
        return;
    }
    if(now.x2<=seg[t<<1].rr){
        update(t<<1,now);
    }
    else if(now.x1>=seg[t<<1|1].rl){
        update(t<<1|1,now);
    }
    else{
        line tmp;
        tmp=now;
        tmp.x2=seg[t<<1].rr;
        update(t<<1,tmp);
        tmp=now;
        tmp.x1=seg[t<<1|1].rl;
        update(t<<1|1,tmp);
    }
    push_up(t);
}
int main()
{
    int n,kase=0,num;
    double x1,x2,y1,y2;
    while(scanf("%d",&n)!=EOF){
        kase++;
        if(n==0){
            break;
        }
        num=1;
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            l[num].h=y1;
            l[num].x1=x1;
            l[num].x2=x2;
            l[num].cnt=1;
            x[num]=x1;
            num++;
            l[num].h=y2;
            l[num].x1=x1;
            l[num].x2=x2;
            l[num].cnt=-1;
            x[num]=x2;
            num++;
        }
        sort(x+1,x+num);
        sort(l+1,l+num);
        build(1,num-1,1);
        update(1,l[1]);
        double ans=0;
        for(int i=2;i<num;i++){
            ans+=seg[1].len*(l[i].h-l[i-1].h);
            update(1,l[i]);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",kase,ans);
    }
}
