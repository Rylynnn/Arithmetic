#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 10000000000LL
#define MAX 6007
#define ll long long
using namespace std;
ll n,m,ans,cnt=1;
ll head[MAX],q[MAX],h[MAX];
struct data{ll to,next,v;}e[MAX*20];
void ins(ll u,ll v,ll w)
{
	cnt++;e[cnt].to=v;e[cnt].next=head[u];
	head[u]=cnt;e[cnt].v=w;
}
void insert(ll u,ll v,ll w)
{ins(u,v,w);ins(v,u,w);}
bool bfs()
{
	memset(h,-1,sizeof(h));
	ll t=0,w=1,now;
	q[t]=1;h[1]=0;
	while(t!=w)
	{
		now=q[t];t++;if(t==MAX)t=0;
		for(ll i=head[now];i;i=e[i].next)
		{
			if(e[i].v&&h[e[i].to]==-1)
			{
				h[e[i].to]=h[now]+1;
				q[w++]=e[i].to;
				if(w==MAX)w=0;
			}
		}
	}
	if(h[n]==-1)return 0;
	return 1;
}
ll dfs(ll x,ll f)
{
	if(x==n)return f;
	ll w,used=0;
	for(ll i=head[x];i;i=e[i].next)
	{
		if(e[i].v&&h[e[i].to]==h[x]+1)
		{
			w=dfs(e[i].to,min(f-used,e[i].v));
			used+=w;e[i].v-=w;e[i^1].v+=w;
			if(used==f)return f;
		}
	}
	if(!used)h[n]==-1;
	return used;
}
void dinic(){while(bfs())ans+=dfs(1,inf);}
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=m;i++){
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        insert(u,v,w);
    }
    dinic();
    printf("%lld",ans);
    return 0;
}
