/*
想复杂了，普通的背包，dp[i]表示以线段i结尾的最大的价值
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
struct node{
    ll a,b,c,len;
}seg[1009];
bool cmp(node i,node j){
    if(i.a!=j.a){
        return i.a<j.a;
    }
    else{
        if(i.b!=j.b){
            return i.b<j.b;
        }
        else{
            return i.c<j.c;
        }
    }
}
int main()
{
    int n;
    ll dp[1009];
    while(scanf("%d",&n)!=EOF){
        ll maxm=0;
        for(int i=0;i<n;i++){
            scanf("%lld%lld%lld",&seg[i].a,&seg[i].b,&seg[i].c);
            seg[i].len=seg[i].b-seg[i].a+1;
            maxm=max(maxm,seg[i].b);
        }
        sort(seg,seg+n,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i]=seg[i].c;
            for(int j=0;j<i;j++){
                if(seg[j].b<=seg[i].a){
                    dp[i]=max(dp[i],dp[j]+seg[i].c);
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
