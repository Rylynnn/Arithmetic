#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
struct edge{
    int u;
    int v;
    int val;
}num[5007];
int dp[5007][5007],par[5007][5007];
void dfs(int ran,int i){//(不可置信我居然很快的就写对了。。。
    if(i==1){
        return;
    }
    dfs(ran-1,par[ran][i]);
    printf(" %d",i);
}
int main()
{
    int n,m,t;
    int a,b,c,ans;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF){
        memset(par,0,sizeof(par));
        memset(dp,INF,sizeof(dp));
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            num[i].u=a;
            num[i].v=b;
            num[i].val=c;
        }
        dp[1][1]=0;
        for(int i=2;i<=n;i++){
            for(int j=0;j<m;j++){//总共m条边，直接枚举就行了
                if(dp[i][num[j].v]>dp[i-1][num[j].u]+num[j].val){
                    dp[i][num[j].v]=dp[i-1][num[j].u]+num[j].val;
                    par[i][num[j].v]=num[j].u;
                    //printf("%d %d\n",num[j].v,par[i][num[j].v]);
                }
            }
        }
        ans=0;
        for(int i=2;i<=n;i++){
            if(dp[i][n]<=t){
                ans=i;
            }
        }
        for(int i=2;i<=n;i++){
        }
        printf("%d\n",ans);
        printf("1");
        dfs(ans,n);
        printf("\n");
    }
}
