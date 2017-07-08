#include <cstdio>
#include <cstring>
#include <queue>
#define N 100000
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
    if(!q.empty()){
        q.pop();
    }
    q.push(step(b,0));
    vis[b]=1;
    while(!q.empty()){
        step a=q.front();
        q.pop();
        if(a.x==e){
            printf("%d\n",a.s);
            break;
        }
        if(a.x-1>=0&&a.x-1<=N&&!vis[a.x-1]){
            q.push(step(a.x-1,a.s+1));
            vis[a.x-1]=1;
        }
        if(a.x+1>=0&&a.x+1<=N&&!vis[a.x+1]){
            q.push(step(a.x+1,a.s+1));
            vis[a.x+1]=1;
        }
        if(a.x*2>=0&&(a.x*2)<=N&&!vis[a.x*2]){
            q.push(step(a.x*2,a.s+1));
            vis[a.x*2]=1;
        }
    }

    return 0;
}
