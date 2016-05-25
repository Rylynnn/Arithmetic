/*0x3f3f3f3f=10^9!!!!!!*/
#include <bits/stdc++.h>
#define INF 3000000000
using namespace std;
long long maxm[100007],minm[100007];
struct node{
    int num;
    long long x;
}c[100007];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main()
{
    long long n,dis;
    scanf("%I64d",&n);
    memset(maxm,0,sizeof(maxm));
    for(int i=1;i<=n;i++){
        c[i].x=0;
        minm[i]=INF;
    }
    for(int i=1;i<=n;i++){
        scanf("%I64d",&c[i].x);
        c[i].num=i;
    }
    sort(c+1,c+n+1,cmp);
    minm[c[1].num]=c[2].x-c[1].x;
    maxm[c[1].num]=c[n].x-c[1].x;
    minm[c[n].num]=c[n].x-c[n-1].x;
    maxm[c[n].num]=c[n].x-c[1].x;
    for(int i=2;i<n;i++){
        maxm[c[i].num]=max(c[i].x-c[1].x,c[n].x-c[i].x);
        minm[c[i].num]=min(c[i].x-c[i-1].x,c[i+1].x-c[i].x);
    }
    for(int i=1;i<=n;i++){
        printf("%I64d %I64d\n",minm[i],maxm[i]);
    }
    return 0;
}
