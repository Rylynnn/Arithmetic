#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int t,n;
    int i,j,sum;
    double p;
    int m[1100];
    double point[1100],dp[11000];
    scanf("%d",&t);
    while(t--){
        scanf("%lf%d",&p,&n);
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%d%lf",&m[i],&point[i]);
            sum+=m[i];
            //printf("%d\n",sum);
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=1;i<=n;i++){
            for(j=sum;j>=m[i];j--){
                dp[j]=max(dp[j],dp[j-m[i]]*(1-point[i]));
                //printf("%d:%lf\n",j,dp[j]);
            }
        }
        for(i=sum;i>=0;i--){
            //printf("%lf%lf\n",dp[i],1-p);
            if(dp[i]-(1-p)>0.000000001){
                 printf("%d\n",i);
                 break;
            }
        }
    }
    return 0;
}
