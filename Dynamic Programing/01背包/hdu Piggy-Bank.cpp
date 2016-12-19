#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int t,e,f,n,v,i,j;
    int p[510],w[510];
    int dp[11000];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&e,&f,&n);
        v=f-e;
        for(i=1;i<=n;i++){
            scanf("%d%d",&p[i],&w[i]);
        }
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        for(i=1;i<=n;i++){
            for(j=w[i];j<=v;j++){
                if(dp[j]!=-1&&dp[j-w[i]]!=-1){//后期每次更新，完全背包
                    dp[j]=min(dp[j-w[i]]+p[i],dp[j]);
                }
                else if(dp[j]==-1&&dp[j-w[i]]!=-1){//从头更新
                    dp[j]=dp[j-w[i]]+p[i];
                }
                //printf("%d ",dp[j]);
            }
            //printf("\n");
        }
        if(dp[v]!=-1){
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
        }
        else{
            printf("This is impossible.\n");
        }
    }
    return 0;
}
