#include <bits/stdc++.h>
using namespace std;
int a[107][107];
int dp[107][107];
int main()
{
    int t,n,ans;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&n);
            memset(a,0,sizeof(a));
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++){
                    scanf("%d",&a[i][j]);
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=i;j++){
                    dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
                }
            }
            ans=-1;
            for(int i=1;i<=n;i++){
                ans=max(ans,dp[n][i]);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
