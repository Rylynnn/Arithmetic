/*************************************************************************
    > File Name: 1007.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/17 16:36:37 2017
 ************************************************************************/
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MX = 205;
struct node {
    int x,y;
} a[MX];
int dp[MX][MX];
char str[MX];
int main() {
    int T,cas=0,n,nn,cnt,i,j,k,l;;
    memset(dp,0x3f,sizeof(dp));
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--) {
        printf("Case #%d: ",++cas);
        scanf("%s",str+1);
        n=strlen(str+1),nn=0,cnt=1;
        char pre=str[1];
        for(i=2; i<=n; i++,cnt++) {
            if(str[i]!=pre) {
                a[++nn].x=pre-'0';
                a[nn].y=cnt;
                cnt=0;
                pre=str[i];
            }
        }
        a[++nn].x=pre-'0';
        a[nn].y=cnt;
        n=nn;
        for(i=1; i<=n; i++) dp[i][i]=a[i].y==1?2:1;
        for(l = 1; l < n; l++) {
            for(i = 1; i + l <= n; i++) {
                j = i + l;
                dp[i][j]=0x3f3f3f3f;
                if(a[i].x==a[j].x) {
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]+(a[i].y+a[j].y>=3?0:1));
                    if(a[i].y+a[j].y<=3) {
                        for(k=i+1; k<j; k++) {
                            if(a[j].x==a[k].x&&a[k].y==1) dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k+1][j-1]);
                        }
                    }
                }
                for(k = i; k < j; k++) dp[i][j] = min(dp[i][j],dp[i][k] + dp[k + 1][j]);
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}
