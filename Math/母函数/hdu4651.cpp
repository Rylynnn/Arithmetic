#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#define inf 10000000000LL
#define MAX 100007
#define MOD 1000000007
#define ll long long
using namespace std;
ll dp[100007];
ll p(){//数拆分O(n√n)广义五边形数
    memset(dp,0,sizeof(dp));
    dp[1]=dp[0]=1;
    dp[2]=2,dp[3]=3;
    int now;
    for(int i=4;i<MAX;i++){
        now=1;
        for(int j=1;;j++){
            ll a=(j*j*3+j)/2;
            ll b=(j*j*3-j)/2;
            if(a>i&&b>i){
                break;
            }
            if(a<=i){
                dp[i]=(dp[i]+dp[i-a]*now+MOD)%MOD;
            }
            if(b<=i){
                dp[i]=(dp[i]+dp[i-b]*now+MOD)%MOD;
            }
            now*=-1;
        }
    }
    return 0;
}
int main()
{
    int t;
    ll n,ans;
    p();
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%I64d",&n);
            printf("%I64d\n",dp[n]%MOD);
        }
    }
}

