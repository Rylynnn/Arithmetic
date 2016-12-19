#include <bits/stdc++.h>
using namespace std;
int vis[100007],d[100007];
void bfs(int n,int k){
    queue<int> q;
    int now;
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    q.push(n);
    vis[n]=1;
    while(!q.empty()){
        now=q.front();
        q.pop();
        if(now==k){
            break;
        }
        if(now-1>=0&&!vis[now-1]){
            q.push(now-1);
            vis[now-1]=1;
            d[now-1]=d[now]+1;
        }
        if(now+1<100007&&!vis[now+1]){
            q.push(now+1);
            vis[now+1]=1;
            d[now+1]=d[now]+1;
        }
        if((now<<1)<100007&&!vis[now<<1]){
            q.push(now<<1);
            vis[now<<1]=1;
            d[now<<1]=d[now]+1;
        }
    }
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        bfs(n,k);
        printf("%d\n",d[k]);
    }
}
