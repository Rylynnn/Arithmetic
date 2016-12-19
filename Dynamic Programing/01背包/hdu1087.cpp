#include <bits/stdc++.h>
using namespace std;
long long dp[1007],a[1007];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            dp[i]=a[i];
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(a[j]<a[i]){
                    dp[i]=max(dp[j]+a[i],dp[i]);
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        printf("%I64d\n",ans);
    }

}
