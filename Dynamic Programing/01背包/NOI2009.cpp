#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define MOD 1024523
#define INF 0x3f3f3f3f
using namespace std;
int n,m,dp[507][507][507],l;
char a[507],b[507];
int main()
{
    //freopen("in.txt","r",stdin);

    while(scanf("%d%d",&n,&m)!=EOF){
        memset(dp,0,sizeof(dp));
        scanf("%s%s",a+1,b+1);
        reverse(a+1,a+1+n);
        reverse(b+1,b+1+m);
        dp[0][0][0]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    l=i+j-k;
                    if(a[i+1]==a[k+1]){
                        dp[i+1][j][k+1]=(dp[i+1][j][k+1]+dp[i][j][k])%MOD;
                    }
                    if(a[i+1]==b[l+1]){
                        dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k])%MOD;
                    }
                    if(b[j+1]==a[k+1]){
                        dp[i][j+1][k+1]=(dp[i][j+1][k+1]+dp[i][j][k])%MOD;
                    }
                    if(b[j+1]==b[l+1]){
                        dp[i][j+1][k]=(dp[i][j+1][k]+dp[i][j][k])%MOD;
                    }
                }
            }
        }
        printf("%d\n",dp[n][m][n]);
    }
    return 0;
}
