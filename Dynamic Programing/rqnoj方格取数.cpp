#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[200][200];
int squ[200][200];
int dodp(int i,int j);
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    memset(squ,0,sizeof(squ));
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&squ[i][j]);
        }
    }
    dp[0][0]=squ[0][0];
    printf("%d",dodp(n,n));
}
int dodp(int i,int j){
    if(j==0){
        return dp[i][j]=squ[i][j]+dp[i-1][j];
    }
    if(i==0){
        return dp[i][j]=squ[i][j]+dp[i][j-1];
    }
    return dp[i][j]=max(dodp(i-1,j),dodp(i,j-1))+squ[i][j];
}
