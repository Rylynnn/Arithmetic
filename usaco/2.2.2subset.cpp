/*
ID: 15829681
LANG: C++
TASK: subset
*/
/*************************************************************************
    > File Name: 2.2.2subset.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年07月26日 星期三 01时44分05秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#define FILE
using namespace std;
int main()
{
    #ifdef FILE
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    int sum;
    sum = (1 + n) * n / 2;
    if(sum % 2 != 0){
        printf("0\n");
        return 0;
    }
    sum /= 2;
    long long dp[47][407];
    memset(dp, 0, sizeof(dp));
    dp[1][1] = 1;
    dp[1][0] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j - i >= 0){
                dp[i][j] = dp[i-1][j-i] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("%lld\n", dp[n][sum] / (long long)2); 
    return 0;
}
