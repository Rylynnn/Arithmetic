/**************************************************************
    Problem: 3052
    User: Yzx835
    Language: C++
    Result: Accepted
    Time:121317 ms
    Memory:51528 kb
****************************************************************/
 
#include <bits/stdc++.h>
#define LL long long
#define N 200020
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,qq;LL ans[N];
int head[N],pos,pa[N];
struct edge{int to,next;}e[N<<1];
void insert(int x,int y)
{pos++;e[pos].to=y,e[pos].next=head[x],head[x]=pos;}
int st[N],top;
int dep[N],f[N][30],dfn[N],sz;
int bel[N],blo,size[N],cnt,fav[N],six[N];
int dfs(int u,int fa)
{
    pa[u]=f[u][0]=fa;dfn[u]=++sz;
    int sze=0;
    for(int i=head[u];i;i=e[i].next)
    {
        int v=e[i].to;
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        sze+=dfs(v,u);
        if(sze>=blo)
        {
            cnt++;
            for(int j=1;j<=sze;j++)
                bel[st[top--]]=cnt;
            sze=0;
        }
    }st[++top]=u;
    return sze+1;
}
void work()
{
    for(int k=1,j=2;j<=n;k++,j<<=1)
        for(int i=1;i<=n;i++)
            f[i][k]=f[f[i][k-1]][k-1];
}
int lca(int x,int y)
{
    if(dep[x]<dep[y])swap(x,y);
    int tmp=dep[x]-dep[y];
    for(int k=0,j=1;j<=tmp;j<<=1,k++)
        if(tmp&j)x=f[x][k];
    while(x!=y)
    {
        int j=0;
        while(f[x][j]!=f[y][j])j++;
        if(j)j--;
        x=f[x][j],y=f[y][j];
    }return x;
}
int tot1,tot2;
struct node{int x,y,id;}q[N];
bool operator < (node a,node b)
{
    if(bel[a.x]!=bel[b.x])return bel[a.x]<bel[b.x];
    else if(dfn[a.y]!=dfn[b.y])return dfn[a.y]<dfn[b.y];
}
int ll,rr,tt,tot;
bool vis[N];
unordered_map<int, int>num[2]; int now;
void del(int x)
{
	now-=num[six[x]^1][fav[x]];
	num[six[x]][fav[x]]--;
}
void add(int x)
{
	now+=num[six[x]^1][fav[x]];
	num[six[x]][fav[x]]++;
}
void doit(int x)
{
	if(vis[x])del(x);
	else add(x);
	vis[x]^=1;
}
void work(int x,int y)
{
    int lc=lca(x,y);
    while(x!=lc)
        doit(x),x=pa[x];
    while(y!=lc)
        doit(y),y=pa[y];
}
void solve()
{
    for (int i=1;i<=tot;i++)
        if (bel[q[i].y]<bel[q[i].x]) swap(q[i].x,q[i].y);
    sort(q+1,q+1+tot);
    work(q[1].x,q[1].y);
    int lc=lca(q[1].x,q[1].y);
    doit(lc);ans[q[1].id]=(LL)now;doit(lc);
    for(LL i=2;i<=tot;i++)
    {                                               
        work(q[i].x,q[i-1].x);
        work(q[i].y,q[i-1].y);
        int lc=lca(q[i].x,q[i].y);
        doit(lc);ans[q[i].id]=(LL)now;
        doit(lc);
    }
}
/*
4 3 5
1 9 2
7 6 5 1
2 3 
3 1
3 4
1 2 3 2
1 1 2
1 4 2
0 2 1
1 1 2
1 4 2
*/
/*
8
0 0 1 0 1 1 1 1
3 2 2 2 2 3 2 1
1 2
1 3
2 4
2 5
3 6
3 7
6 8
3
2 3
4 6
5 1
*/
/*
7
1 1 0 1 0 0 1
9 9 9 2 2 9 9
2 6
1 2
4 2
6 5
3 6
7 4
4
1 3
7 5
1 7
3 5

*/
int main()
{
//  freopen("in.txt","r",stdin);
//  freopen("my.txt","w",stdout);
    n=read();blo=sqrt(n);
    for(int i=1;i<=n;i++)six[i]=read();
    for(int i=1;i<=n;i++)fav[i]=read();
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        insert(x,y);insert(y,x);
    }dfs(1,0);work();
    while(top)bel[st[top--]]=cnt;
    qq=read();
    for(int i=1;i<=qq;i++){q[++tot].x=read(),q[tot].id=tot,q[tot].y=read();}
	solve();
    for(int i=1;i<=tot;i++)
        printf("%lld\n",ans[i]);
    return 0;
}
