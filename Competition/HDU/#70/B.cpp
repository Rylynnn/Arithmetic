#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[2][2009];
int a[25];
bool can(int b){

}
int main()
{
    int t,n,m,b,i,j,dp[2][2009],sum;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(i=1; i<=n; i++) {
            scanf("%d",&a[i]);
            sum+=a[i];
            dp[i][0]=1;
            //cout<<a[i];
        }
        sort(a+1,a+n);
        dp[0][0]=dp[1][0]=1;
        for(i=1;i<=n+1;i++){
            for(j=0;j<=2008;j++){
                if(dp[(i-1)&1][j]){
                    dp[i&1][j+a[i]]=dp[i&1][j]=1;
                    if(j-a[i]>=0){
                        dp[i&1][j-a[i]]=1;
                    }
                }
            }
        }
        for(i=n;i>=1;i++){
            for(j=0;j<=2008;j++){
                if(dp[(i+1)&1][j]){
                    dp[i&1][j]=1;
                    if(j+a[i])
                    if(j-a[i]>=0){
                        dp[i&1][j-a[i]]=1;
                    }
                }
            }
        }
        for(i=1;i<=2008;i++){
            if(dp[0][i]||dp[1][i]){
                cout<<i;
            }
        }
        scanf("%d",&m);
        while(m--) {
            scanf("%d",&b);
            if(b>=0) {
                if(dp[0][b]==1||dp[1][b]==1) {
                    printf("YES\n");
                }
                else {
                    printf("NO\n");
                }
            }
            else {
                printf("NO\n");
            }
        }
    }

}
