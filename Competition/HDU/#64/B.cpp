#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[100005][3];
int a(int x)
{
    return (1890*x+143)%10007;
}
int main()
{
    int num,n,i;
    while(scanf("%d",&num)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=1; i<=num; i++)
        {
            scanf("%d",&n);
            dp[i][0]=dp[i-1][0]+n;
            dp[i][1]=max(dp[i-1][0]+a(n),dp[i-1][1]+a(n));
            dp[i][2]=max(dp[i-1][1]+n,dp[i-1][2]+n);
        }
        printf("%d\n",max(dp[num][0],max(dp[num][1],dp[num][2])));
    }
    return 0;
}
