#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=101111;
int a[maxn][11];
int dp[maxn][11];
int N,mt,x,t,t2;
inline void init()
{
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    return ;
}
int dpstart()
{
    dp[1][5]=a[1][5];
    dp[1][6]=a[1][6];
    dp[1][4]=a[1][4];
    for(int i=2;i<=mt;i++)
    {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+a[i][0];
        for(int j=1;j<=9;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1])) + a[i][j];
        }
        dp[i][10]=max(dp[i-1][9],dp[i-1][10]) + a[i][10];
    }
    t2=0;
    for(int i=0;i<=10;i++)
    {
        if(dp[mt][i] > t2)
        {
            t2=dp[mt][i];
        }
    }
    return t2;
}
int main()
{
    while( ~scanf("%d",&N) )
    {
        if(N==0)
        {
            break;
        }
        mt=0;
        init();
        for(int i=1;i<=N;i++)
        {
            scanf("%d%d",&x,&t);
            if(t>mt)
            {
                mt=t;
            }
            a[t][x]++;
        }
        cout<<dpstart()<<endl;
    }
    return 0;
}
