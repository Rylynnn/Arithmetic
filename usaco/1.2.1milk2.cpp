/*
ID: 15829681
LANG: C++
TASK: milk2
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define LOCAL
#define N 5005
using namespace std;
struct node{
    int l,r;
}a[N];
bool cmp (node a,node b){
    if(a.l==b.l){
        return a.r<b.r;
    }
    else{
        return a.l<b.l;
    }
}
int main()
{
    #ifdef LOCAL
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    #endif
    int n,now,no,i;
    //priority_queue<node,vector<node>,greater<node> >q;
    scanf("%d",&n);
    scanf("%d%d",&a[1].l,&a[1].r);
    //q.push(a);
    no=0;
    for(i=2;i<=n;i++){
        scanf("%d%d",&a[i].l,&a[i].r);
    }
    sort(a+1,a+n+1,cmp);//以左端点的大小作为第一标准排序
    now=a[1].r-a[1].l;
    node p=a[1];//p用来储存当前正在添加的区间
    for(i=2;i<=n;i++){
        if(a[i].l<=p.r&&a[i].l>=p.l){//如果新的区间左端点在当前区间中
            if(a[i].r>p.r){//考察新区间的右端点，如果不在区间中，更新当前区间长度及右端点
                now=max(now,a[i].r-p.l);
                p.r=a[i].r;
            }
        }
        else{
            //printf("1");
            if(a[i].r-a[i].l>now){//对于不满足条件的新区间，进行区间更新的准备工作，可能更新区间长度最大值
                now=a[i].r-a[i].l;
            }
            //printf("%d",now);
            no=max(no,a[i].l-p.r);//更新区间间长度最大值
            //printf("%d",no);
            p=a[i];//更新当前区间
        }
    }
    printf("%d %d\n",now,no);
    return 0;
}
