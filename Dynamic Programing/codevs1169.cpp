/*
因为来回的路径不能重合，所以同时从头尾做
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int m[209][209],dp[209][209][209];
int a,b;
int main()
{
    while(scanf("%d%d",&a,&b)!=EOF){
        memset(m,0,sizeof(m));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                scanf("%d",&m[i][j]);
            }
        }
        int num=a+b-2;
        for(int k=1;k<=num;k++){
            for(int i=1;i<=a;i++){
                for(int j=1;j<=a;j++){
                    if(i!=j||i==a&&j==a&&k==num)
                    dp[k][i][j]=max(max(dp[k-1][i][j],dp[k-1][i-1][j-1]),max(dp[k-1][i-1][j],dp[k-1][i][j-1]))+m[i][k-i+2]+m[j][k-j+2];
                }
            }
        }
        printf("%d\n",dp[num][a][a]);
    }
}
