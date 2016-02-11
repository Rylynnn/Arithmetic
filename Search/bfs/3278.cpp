#include <cstdio>
#include <cstring>
#include <queue>
#define N 100010
using namespace std;
struct step{
    int x;
    int s;
    step(){
    }
    step(int a,int b){
        x=a;
        s=b;
    }
};
queue<step>q;
int vis[N];
int main()
{
    int b,e;
    scanf("%d%d",&b,&e);
    memset(vis,0,sizeof(vis));
    q.push(step(b,0));
    vis[b]=1;
    while(!q.empty()){
        step a=q.front();
        if(a.x==e){
            printf("%d\n",a.s);
            break;
        }
        else{
            if(a.x-1>0&&!vis[a.x-1]){
                q.push(step(a.x-1,a.s+1));
                vis[a.x-1]=1;
            }
            if(a.x+1<=N&&!vis[a.x+1]){
                q.push(step(a.x+1,a.s+1));
                vis[a.x+1]=1;
            }
            if((a.x<<1)<=N&&!vis[a.x<<1]){
                q.push(step(a.x<<1,a.s+1));
                vis[a.x<<1]=1;
            }
            q.pop();
        }
    }
    return 0;
}
