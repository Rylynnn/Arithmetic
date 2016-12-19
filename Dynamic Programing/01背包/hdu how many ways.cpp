#include<cstdio>
#include<cstring>
#define LOCAL
int main()
{
    #ifdef LOCAL
        freopen("in.in","r",stdin);
    #endif
    int a[110][110];
    int dp[110][110];
    int t,n,m,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
            }
        }
        dp[1][1]=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i-1][j]>0){
                    dp[i][j]+=dp[i-1][j];
                    //dp[i][j]%=10000;
                }
                if(a[i][j-1]>0){
                    dp[i][j]+=dp[i][j-1];
                    //dp[i][j]%=10000;
                }
            }
        }
        printf("%d",dp[n][m])%10000;
    }

}
