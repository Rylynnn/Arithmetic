#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline double Max(double a,double b) {
	return a>b?a:b;
}
int main()
{
    int n,m,i,j;
    double dp[11000];
    int c[11000];
    double v[11000];
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0){
            break;
        }
        for(i=1;i<=m;i++){
            scanf("%d%lf",&c[i],&v[i]);
        }
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;i++){
            for(j=n;j>=c[i];j--){
                dp[j]=Max(dp[j],1-(1-dp[j-c[i]])*(1-v[i]));
                //printf("%lf\n",dp[j]);
            }
        }
        printf("%.1lf%%\n",dp[n]*100);
    }
    return 0;
}
