/*
用四维表示用每种牌，多少个时候能取到的最大值
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int n,m;
int a[357],b[5],c;
int dp[47][47][47][47];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&c);
            b[c]++;
        }
        dp[0][0][0][0]=a[0];
        for(int i=0;i<=b[1];i++){
            for(int j=0;j<=b[2];j++){
                for(int k=0;k<=b[3];k++){
                    for(int p=0;p<=b[4];p++){
                        if(i>=1){
                            dp[i][j][k][p]=max(dp[i][j][k][p],dp[i-1][j][k][p]+a[i+j*2+k*3+p*4]);
                        }
                        if(j>=1){
                            dp[i][j][k][p]=max(dp[i][j][k][p],dp[i][j-1][k][p]+a[i+j*2+k*3+p*4]);
                        }
                        if(k>=1){
                            dp[i][j][k][p]=max(dp[i][j][k][p],dp[i][j][k-1][p]+a[i+j*2+k*3+p*4]);
                        }
                        if(p>=1){
                            dp[i][j][k][p]=max(dp[i][j][k][p],dp[i][j][k][p-1]+a[i+j*2+k*3+p*4]);
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[b[1]][b[2]][b[3]][b[4]]);
    }
}
