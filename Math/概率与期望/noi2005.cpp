#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
int mm[1007][1007],d[1007][1007],vis[1007],now,n,m,c,e,a,b;
void bfs(int x){//找出任意两点之间的最短路
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(x);
    vis[x]=1;
    d[x][x]=0;
    while(!q.empty()){
        now=q.front();
        q.pop();
        vis[now]=1;
        for(int i=1;i<=n;i++){
            if(!vis[i]&&mm[now][i]==1){
                if(d[x][i]>d[x][now]+1){
                    d[x][i]=d[x][now]+1;
                    q.push(i);
                }
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&e)!=EOF){
        scanf("%d%d",&c,&m);
        memset(d,INF,sizeof(d));
        for(int i=0;i<e;i++){
            scanf("%d%d",&a,&b);
            mm[a][b]=mm[b][a]=1;
        }
        for(int i=0;i<n;i++){
            bfs(i);
        }
    }
}
