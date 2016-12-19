#include <bits/stdc++.h>
using namespace std;
typedef struct node{
    int x,y;
}knight;
int mov[8][2]={-2,-1,-2,1,-1,-2,-1,2,1,-2,1,2,2,-1,2,1};
int vis[10][10],d[10][10];
void bfs(int ax,int ay,int bx,int by){
    queue<knight> q;
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    knight a,now,nn;
    a.x=ax,a.y=ay;
    q.push(a);
    vis[a.x][a.y]=1;
    d[a.x][a.y]=0;
    while(!q.empty()){
        now=q.front();
        q.pop();
        if(now.x==bx&&now.y==by){
            break;
        }
        for(int i=0;i<8;i++){
            nn.x=now.x+mov[i][0];
            nn.y=now.y+mov[i][1];
            if(nn.x>=0&&nn.x<8&&nn.y>=0&&nn.y<8&&vis[nn.x][nn.y]==0){
                q.push(nn);
                vis[nn.x][nn.y]=1;
                d[nn.x][nn.y]=d[now.x][now.y]+1;
            }
        }
    }

}
int main()
{
    string a,b;
    while(cin>>a>>b){
        bfs(a[0]-'a',a[1]-'0'-1,b[0]-'a',b[1]-'0'-1);
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<d[b[0]-'a'][b[1]-'0'-1]<<" knight moves."<<endl;
    }

}
