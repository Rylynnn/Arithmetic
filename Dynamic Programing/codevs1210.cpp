#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
ll n,dp[109][109],m[109][109];
ll a,b;
int main()
{
    while(scanf("%lld",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=i;j++){
                scanf("%lld",&m[i][j]);
            }
        }
        dp[1][1]=m[1][1];
        for(ll i=2;i<=n;i++){
            for(ll j=1;j<=i;j++){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+m[i][j];
            }
        }
        ll ans=-INF;
        for(ll i=1;i<=n;i++){
            ans=max(ans,dp[n][i]);
        }
        printf("%lld\n",ans);
    }
}

