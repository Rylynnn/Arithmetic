#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cmath>
#define MAX 50008
#define lson (t<<1)
#define rson (t<<1|1)
using namespace std;
struct node{
    int sum,maxm,lmx,rmx;
}seg[MAX<<2];
void push_up(int t){
    seg[t].sum=seg[lson].sum+seg[rson].sum;//整个区间的总和
    seg[t].lmx=max(seg[lson].lmx,seg[lson].sum+seg[rson].lmx);//从最左端开始的最大值等于（lson的lmx）和（lson的sum+rson的lmx）的最大值
    seg[t].rmx=max(seg[rson].rmx,seg[rson].sum+seg[lson].rmx);
    seg[t].maxm=max(max(seg[lson].maxm,seg[rson].maxm),seg[lson].rmx+seg[rson].lmx);
    return;
}
void build(int l,int r,int t){
     if(l==r){
        scanf("%d",&seg[t].sum);
        seg[t].maxm=seg[t].lmx=seg[t].rmx=seg[t].sum;
        return;
     }
     int mid=(l+r)>>1;
     build(l,mid,lson);
     build(mid+1,r,rson);
     push_up(t);
}
node query(int l,int r,int nl,int nr,int t){
    if(nl==l&&nr==r){
        return seg[t];
    }
    node ll,rr,now;
    int mid=(nl+nr)>>1;
    if(r<=mid){
        return query(l,r,nl,mid,lson);
    }
    else if(l>mid){
        return query(l,r,mid+1,nr,rson);
    }
    ll=query(l,mid,nl,mid,lson);
    rr=query(mid+1,r,mid+1,nr,rson);
    now.sum=ll.sum+rr.sum;
    now.lmx=max(ll.lmx,ll.sum+rr.lmx);
    now.rmx=max(rr.rmx,rr.sum+ll.rmx);
    now.maxm=max(max(ll.maxm,rr.maxm),ll.rmx+rr.lmx);
    return now;
}
int main()
{
    node ans;
    int n,m,x,y;
    while(scanf("%d",&n)!=EOF){
        build(1,n,1);
        scanf("%d",&m);
        while(m--){
            scanf("%d%d",&x,&y);
            ans=query(x,y,1,n,1);
            printf("%d\n",ans.maxm);
        }
    }
    return 0;
}
