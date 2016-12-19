#include <cstdio>
#define MOD 10007
#define N 1000010
int dp[N];
int main()
{
    int n,i;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(i=4;i<=N;i++){
        dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%MOD;
    }
    while(scanf("%d",&n)!=EOF){
        printf("%d\n",dp[n]);
    }
    return 0;
}
