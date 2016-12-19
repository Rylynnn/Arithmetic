/*数据量非常小，于是换成01背包*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,m;
    int i,j;
    int v[110],w[110],num[110];
    int dp[110];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        int k;
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&v[i],&w[i],&num[i]);
        }
        for(i=1;i<=m;i++){
            for(k=1;k<=num[i];k++){
                for(j=n;j>=v[i];j--){
                    dp[j]=max(dp[j-v[i]]+w[i],dp[j]);
                    //printf("%d ",dp[j]);
                }
            }
        }
        printf("%d\n",dp[n]);
    }

}
