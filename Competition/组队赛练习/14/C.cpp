#include <bits/stdc++.h>
#define N 100007

#define lson (i << 1)
#define rson ((i <<1) | 1)

using namespace std;
struct node{
    int l,r;
    int p;
    int num;
}seg[N*4];
int a[N];
void push(int i){
    if(seg[lson].p>seg[rson].p){
        seg[i].p=seg[lson].p;
        seg[i].num=seg[lson].num;
    }
    else if(seg[lson].p==seg[rson].p) {
        seg[i].p = seg[lson].p;
        seg[i].num = min(seg[lson].num, seg[rson].num);
    }
    else{
        seg[i].p=seg[rson].p;
        seg[i].num=seg[rson].num;
    }
}
void build(int i,int b,int e){
    seg[i].l=b;
    seg[i].r=e;
    if(b==e){
        seg[i].p=0;
        seg[i].num=b;
        return;
    }
    int mid=(b+e)>>1;
    build(i<<1,b,mid);
    build((i<<1)|1,mid+1,e);
    push(i);
}
void update(int i,int indx,int j){
    if(seg[i].r==seg[i].l){
        seg[i].p+=j;
        return;
    }
    int mid=(seg[i].r+seg[i].l)/2;
    if(indx<=mid){
        update(lson,indx,j);
    }
    else{
        update(rson,indx,j);
    }
    push(i);
}
int main()
{
    int t,n,q,maxm,maxx,x,pp,ans;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            memset(a,0,sizeof(a));
            scanf("%d%d",&n,&q);
            build(1,1,n);
            ans=0;
            for(int i=1;i<=q;i++){
                scanf("%d%d",&x,&pp);
                update(1,x,pp);
                a[i]=seg[1].num;
            }
            for(int i=q;i>=1;i--){
                //cout<<a[i]<<' ';
                if(a[i]!=a[q]){

                    break;
                }
                ans=i;
            }
            printf("%d\n",ans);
        }
    }
}
