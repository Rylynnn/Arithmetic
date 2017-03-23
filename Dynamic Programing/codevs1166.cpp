#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
ll f[109],dp[109][109],m[109][109];
int a,b;
int main()
{
    f[0]=1;
    while(scanf("%d%d",&a,&b)!=EOF){
        memset(m,0,sizeof(m));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                scanf("%lld",&m[i][j]);
            }
        }
        ll ans=0,nn;
        for(int num=1;num<=a;num++){
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=b;i++){
                dp[i][i]=m[num][i]*2;
            }
            for(int len=2;len<=b;len++){
                nn++;
                for(int i=1;i<=b-len+1;i++){
                    int j=i+len-1;
                    dp[i][j]=2*max(dp[i+1][j]+m[num][i],dp[i][j-1]+m[num][j]);
                }
            }
            ans+=dp[1][b];
        }
        printf("%lld\n",ans);
    }
}

