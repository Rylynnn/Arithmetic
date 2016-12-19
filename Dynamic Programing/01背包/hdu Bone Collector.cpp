/*Âã01±³°ü£¬ÅÅÐòÌ°ÐÄ¿É¹ý*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,v,ans,i,j;
    int value[1100],volumn[1100];
    int dp[1100];
    scanf("%d",&t);
    while(t--&&~scanf("%d%d",&n,&v)){
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            scanf("%d",&value[i]);
        }
        for(i=1;i<=n;i++){
            scanf("%d",&volumn[i]);
        }
        for(i=1;i<=n;i++){
            for(j=v;j>=volumn[i];j--){
                dp[j]=max(dp[j-volumn[i]]+value[i],dp[j]);//01背包
                //printf("%d:%d\n",j,dp[j]);
            }
        }
        ans=0;
        for(i=1;i<=v;i++){
            ans=max(ans,dp[i]);
            //printf("%d",ans);
        }
        printf("%d\n",ans);
    }

}
