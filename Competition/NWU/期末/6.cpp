#include <stdio.h>
int main()
{
    int dp[53][3];
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=1;
    for(i=1; i<n; i++) {
        dp[i][0]=dp[i-1][1]+dp[i-1][2]+1;
        dp[i][1]=dp[i-1][0],dp[i-1][2]+1;
        dp[i][2]=dp[i-1][0],dp[i-1][1]+1;
    }
    dp[n][0]=dp[n-1][1]+dp[n-1][2]+1;
    dp[n][1]=dp[n-1][0],dp[n-1][2]+1;
    dp[n][2]=dp[n-1][0],dp[n-1][1]+1;

}
