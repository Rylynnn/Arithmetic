#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
const int MAXN=22000;
bool visit[MAXN];
queue<int>q1,q2;
vector<vector<int> >adj; //原图
vector<vector<int> >radj;//逆图
vector<vector<int> >dag;//缩点后的图
int n,m,cnt;
int id[MAXN],order[MAXN],ind[MAXN];//强连通分量，访问顺序，入度
void dfs(int u){
    visit[u]=true;
    int i,len=adj[u].size();
    for(i=0;i<len;i++)
      if(!visit[adj[u][i]])
        dfs(adj[u][i]);
    order[cnt++]=u;
}
void rdfs(int u){
    visit[u]=true;
    id[u]=cnt;
    int i,len=radj[u].size();
    for(i=0;i<len;i++)
      if(!visit[radj[u][i]])
        rdfs(radj[u][i]);
}
void two_sat(){
    int i;
    memset(visit,false,sizeof(visit));
    for(cnt=0,i=0;i<2*n;i++)
      if(!visit[i])
        dfs(i);
    memset(id,0,sizeof(id));
    memset(visit,false,sizeof(visit));
    for(cnt=0,i=2*n-1;i>=0;i--)
      if(!visit[order[i]]){
          cnt++;
          rdfs(order[i]);
      }
}
bool solve(){
    for(int i=0;i<n;i++)
      if(id[2*i]==id[2*i+1])
        return false;
   return true;
}
void add(int x,int y){
    adj[x].push_back(y);
    radj[y].push_back(x);
}
int a[MAXN],b[MAXN];
int main()
{
    int T;
    int x,y,z;
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        kase++;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1)b[i]=2;
            else if(a[i]==2)b[i]=3;
            else b[i]=1;
            if(a[i]>b[i])swap(a[i],b[i]);
        }
        adj.assign(2*n,vector<int>());
        radj.assign(2*n,vector<int>());
        bool flag=true;
        while(m--){
            scanf("%d%d%d",&x,&y,&z);
            x--;
            y--;
            if(!flag)continue;
            if(x==y){
                if(z==1)flag=false;
                continue;
            }
            if(z==0){//如果希望结果相等
                if(a[x]!=a[y]){//B两次不等
                    add(2*x,2*y+1);//x局平局，y局赢B的y局
                    add(2*y,2*x+1);//要么全输，要么x局赢，y局平
                }
                if(a[x]!=b[y]){//B的x局和A要赢B的y局结果不等
                    add(2*x,2*y);//两平局，可相等
                    add(2*y+1,2*x+1);//两赢局
                }
                if(b[x]!=a[y]){
                    add(2*x+1,2*y+1);//x局赢局，y局赢局
                    add(2*y,2*x);//a[x]=a[y]两平局
                }
                if(b[x]!=b[y]){
                    add(2*x+1,2*y);//b[x]==a[y]x局赢局，y局平局
                    add(2*y+1,2*x);//a[x]=b[y]x局平局，y局赢局
                }

            }
            else if(z==1){//两次结果不等
                if(a[x]==a[y]){//B两次相等，若要A两次输出均不等，且不输B
                    add(2*x,2*y+1);//x局和B的x局相等，y局赢B的y局
                    add(2*y,2*x+1);//x局和B的y局相等，y局赢B的x局（B的y和x局相等）
                }
                if(a[x]==b[y]){//B的x局和A要赢B的y局结果相等
                    add(2*x,2*y);//x局和B的x局相等，y局和B的y局相等
                    add(2*y+1,2*x+1);//x局和B的x局相等，y局为输局
                }
                if(b[x]==a[y]){
                    add(2*x+1,2*y+1);//x局赢B的x局，y局赢B的y局
                    add(2*y,2*x);//x局赢B的x局，y局为输局
                }
                if(b[x]==b[y]){
                    add(2*x+1,2*y);//x局赢B的x局，y局为平局
                    add(2*y+1,2*x);//x局赢B的x局，y局为平局
                }

            }
        }
        if(!flag){
            printf("Case #%d: no\n",kase);
            continue;
        }
        two_sat();
        if(solve())printf("Case #%d: yes\n",kase);
        else printf("Case #%d: no\n",kase);
    }
    return 0;
}
