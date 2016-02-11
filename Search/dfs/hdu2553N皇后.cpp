#include <bits/stdc++.h>
using namespace std;
int num;
int vis[3][30];
void dfs(int p)
{
    if(p==n) sum++;
    else
        for(int i=0; i<n; i++)
            if(!vis[0][i]&&!vis[1][p+i]&&!vis[2][p-i+n]){
                vis[0][i]=vis[1][p+i]=vis[2][p-i+n]=1;
                dfs(p+1);
                vis[0][i]=vis[1][p+i]=vis[2][p-i+n]=0;
            }
}
int main()
{
    int n;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=10;i++){
        num=0;
        dfs(i);
        a[i]=num;
    }
    while(scanf("%d",&n)!=EOF){

    }

}
