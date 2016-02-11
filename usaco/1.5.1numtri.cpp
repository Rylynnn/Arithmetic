/*
LANG:C++
ID:15829681
TASK:numtri
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define IO
#define N 1005
using namespace std;
int a[N][N];
int dp[N][N];
int main()
{
      #ifdef IO
      freopen("numtri.in","r",stdin);
      freopen("numtri.out","w",stdout);
      #endif // IO
      int r,i,j;
      scanf("%d",&r);
      memset(a,0,sizeof(a));
      memset(dp,0,sizeof(dp));
      for(i=1;i<=r;i++){
            for(j=1;j<=i;j++){
                  scanf("%d",&a[i][j]);
            }
      }
      for(i=1;i<=r;i++){
            for(j=1;j<=i;j++){
                  dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
                  //printf("%d ",dp[i][j]);
            }
            //printf("\n");
      }
      int ans=0;
      for(i=1;i<=r;i++){
            if(dp[r][i]>ans){
                  ans=dp[r][i];
            }
      }
      printf("%d\n",ans);
      return 0;
}
