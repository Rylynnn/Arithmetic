/*
ID: 15929681
LANG: C++
TASK: barn1
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 0x3f3f3f3f
#define LOCAL
using namespace std;
int main()
{
    #ifdef LOCAL
        freopen("barn1.in","r",stdin);
        freopen("barn1.out","w",stdout);
    #endif
    int m,s,c,ans,minm;
    int a[507],dp[507][507];
    while(scanf("%d%d%d",&m,&s,&c)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=c;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+c);
        for(int i=1;i<=c;i++){
            dp[1][i]=a[i]-a[1]+1;
        }
        for(int i=2;i<=m;i++){
            for(int j=1;j<=c;j++){
                minm=MAX;
                for(int k=1;k<j;k++){
                    minm=min(dp[i][k]+a[j]-a[k],minm);
                }
                dp[i][j]=min(dp[i-1][j-1]+1,minm);
                //cout<<dp[i][j]<<' ';
            }
        }
        ans=0;
        printf("%d\n",dp[m][c]);
    }
    return 0;
}
