/*最大递增子段*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 999999999
using namespace std;
int dp[1010];
int a[1010];
int maxm(int i);
int main()
{
    int n,i,ans;
    while(~scanf("%d",&n)&&n!=0){
        memset(a,0,sizeof(a));
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++){
            dp[i]=maxm(i)+a[i];
        }
        ans=-inf;
        for(i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }

}
int maxm(int i){
    int maxv=-inf;
    for(int j=0;j<i;j++){
        if(a[j]<a[i])maxv=max(dp[j],maxv);//j<i&&a[j]<a[i]
    }
    return maxv;
}
