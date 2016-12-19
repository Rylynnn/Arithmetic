#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int squ[110][110];
int dp[110][110];
void dodp(int i,int j);
int main()
{
    int num,n,i,j,k;
    memset(squ,0,sizeof(squ));
    scanf("%d",&num);
    for(k=1;k<=num;k++){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            for(j=1;j<=i;j++){
                scanf("%d",&squ[i][j]);
            }
        }
        for(i=n;i>=1;i--){
            for(j=1;j<=i+1;j++)
                dodp(i,j);
        }
        printf("%d\n",dp[1][1]);
    }
    return 0;
}
void dodp(int i,int j){
    dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+squ[i][j];
}
