#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[1100][1100];
int dp[1100][1100];
int maxm(int j,int k);
int main()
{
    int num,i,j,k;
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for(j=1;j<=n;j++){
            for(k=1;k<=m;k++){
                scanf("%d",&a[j][k]);
            }
        }
        for(j=n;j>=1;j--){
            for(k=m;k>=1;k--){
                dp[j][k]=maxm(j,k)+a[j][k];
                //printf("%d\n",dp[j][k]);
            }
        }
        printf("%d\n",dp[1][1]);
    }
    return 0;
}
int maxm(int j,int k){
    int maxv=-1000,i;
    for(i=k*2;i<=m;i+=k){
        if(dp[j][i]>maxv)maxv=dp[j][i];
    }
    if(j+1>n&&k+1<=m){
        return max(maxv,dp[j][k+1]);
    }
    if(j+1<=n&&k+1>m){
        return max(maxv,dp[j+1][k]);
    }
    else{
        if(maxv>max(dp[j+1][k],dp[j][k+1]))return maxv;
        else return max(dp[j+1][k],dp[j][k+1]);
    }
}
