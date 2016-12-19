#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef struct node{
    int x,y,prex,prey;
    char val;
    int time;
    bool operator < (const node& b)const{
        return time>b.time;
    }
}knight;
knight peo[107][107],now,nn;
string a[107];
int mov[4][2]={-1,0,1,0,0,-1,0,1};
int p,n,m,num;
void bfs(){
    priority_queue<knight>q;
    peo[0][0].time=0;
    q.push(peo[0][0]);
    while(!q.empty()){
        now=q.top();
        q.pop();
        if(now.x==n-1&&now.y==m-1){
            p=1;
            break;
        }
        for(int i=0;i<4;i++){
            nn.x=now.x+mov[i][0];
            nn.y=now.y+mov[i][1];
            if(nn.x>=0&&nn.x<n&&nn.y>=0&&nn.y<m&&a[nn.x][nn.y]=='.'){
                if(peo[nn.x][nn.y].time>peo[now.x][now.y].time+1){
                    peo[nn.x][nn.y].time=peo[now.x][now.y].time+1;
                    //cout<<peo[nn.x][nn.y].time<<endl;
                    peo[nn.x][nn.y].prex=now.x;
                    peo[nn.x][nn.y].prey=now.y;
                    q.push(peo[nn.x][nn.y]);
                }
            }
            else if(nn.x>=0&&nn.x<n&&nn.y>=0&&nn.y<m&&a[nn.x][nn.y]>='1'&&a[nn.x][nn.y]<='9'){
                if(peo[nn.x][nn.y].time>peo[now.x][now.y].time+a[nn.x][nn.y]-'0'+1){
                    peo[nn.x][nn.y].time=peo[now.x][now.y].time+a[nn.x][nn.y]-'0'+1;
                    //cout<<peo[nn.x][nn.y].time<<endl;
                    peo[nn.x][nn.y].prex=now.x;
                    peo[nn.x][nn.y].prey=now.y;
                    q.push(peo[nn.x][nn.y]);
                }
            }
        }
    }
}
void dfs(int i,int j){
    if(i==0&&j==0){
        return;
    }
    dfs(peo[i][j].prex,peo[i][j].prey);
    if(a[i][j]=='.'){
        printf("%ds:(%d,%d)->(%d,%d)\n",peo[i][j].time,peo[i][j].prex,peo[i][j].prey,i,j);
    }
    else if(a[i][j]>='1'&&a[i][j]<='9'){
        num=a[i][j]-'0';
        printf("%ds:(%d,%d)->(%d,%d)\n",peo[i][j].time-num,peo[i][j].prex,peo[i][j].prey,i,j);
        while(--num>=0){
            printf("%ds:FIGHT AT (%d,%d)\n",peo[i][j].time-num,i,j);
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        p=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                peo[i][j].x=peo[i][j].prex=i;
                peo[i][j].y=peo[i][j].prey=j;
                peo[i][j].val=a[i][j];
                peo[i][j].time=INF;
            }
        }
        bfs();
        if(p==1){
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",peo[n-1][m-1].time);
            dfs(n-1,m-1);
            printf("FINISH\n");
        }
        else{
            printf("God please help our poor hero.\n");
            printf("FINISH\n");
        }
    }
}
