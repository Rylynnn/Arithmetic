#include <bits/stdc++.h>
using namespace std;
int n,a,b,k[207],vis[207],d[207],now,up,down;
void bfs(int a,int b){
    queue<int>q;
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    q.push(a);
    vis[a]=1;
    d[a]=0;
    int p=0;
    while(!q.empty()){
        now=q.front();
        q.pop();
        if(now==b){
            p=1;
            break;
        }
        up=now+k[now];
        if(up<=n&&up>0&&!vis[up]){
            vis[up]=1;
            q.push(up);
            d[up]=d[now]+1;
        }
        down=now-k[now];
        if(down>0&&down<=n&&!vis[down]){
            vis[down]=1;
            q.push(down);
            d[down]=d[now]+1;
        }
    }
    if(p==1){
        printf("%d\n",d[b]);
    }
    else{
        printf("-1\n");
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        scanf("%d%d",&a,&b);
        for(int i=1;i<=n;i++){
            scanf("%d",&k[i]);
        }
        bfs(a,b);
    }
    return 0;
}
