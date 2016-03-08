#include <bits/stdc++.h>
int dp[100][100];
using namespace std;
int main()
{
    int a,b,now,i,j;
    long long num;
    while(scanf("%d%d",&a,&b)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[1][2]=dp[2][1]=dp[2][2]=1;
        for(i=1;i<=100;i++){
            for(j=1;j<100;j++){
                if((i!=1&&j!=1)||(i!=1&&j!=2)||(i!=2&&j!=1)||(i!=2&&j!=2))
                dp[i][j]=max(dp[i-1][j+2],dp[i+2][j-1])+1;
            }
        }
    }
}
