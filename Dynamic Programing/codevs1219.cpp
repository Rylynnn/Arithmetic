#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll x1,x2,y1,y2,dp[209][209];
ll a,b;
int main()
{
    while(scanf("%lld%lld",&a,&b)!=EOF){
        memset(dp,0,sizeof(dp));
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        dp[x1][y1]=1;
        for(ll k=x1+1;k<=x2;k++){
            for(ll i=1;i<=b;i++){
                if(k-1>=1&&i-2>=1)
                    dp[k][i]+=dp[k-1][i-2];
                if(k-2>=1&&i-1>=1){
                    dp[k][i]+=dp[k-2][i-1];
                }
                if(k-1>=1&&i+2<=b){
                    dp[k][i]+=dp[k-1][i+2];
                }
                if(k-2>=1&&i+1<=b){
                    dp[k][i]+=dp[k-2][i+1];
                }
            }
        }
        printf("%lld\n",dp[x2][y2]);
    }
}
