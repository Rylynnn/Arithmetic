#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>

using namespace std;
typedef long long LL;

int T,n;
int e[2100000],last[1100000],pre[2100000],v[1100000],w[2100000];
int pp[1100000],f[1100000][4];
int vp[1100000]; 
int num;
int x,y,z;
struct node
{
	int x,fa,i,delta,pos,ny,nz,y,z;
}p,q;
stack<node> S;
void dfs(int x,int fa)
{
	p.x=x,p.fa=fa;
	S.push(p);
	while (1)
	{
		p=S.top();
		pp[p.x]=p.fa;
		f[p.x][0]=f[p.x][1]=v[p.x];
		for (p.i=last[p.x];p.i;i=pre[p.i])
		{
			if (!pp[e[p.i]])
			{
				q.x=e[p.i],q.fa=p.x;
				S.push
				dfs(e[i],x);
				if (f[e[i]][0]-2*w[i]>0) f[x][0]+=f[e[i]][0]-2*w[i],f[x][1]+=f[e[i]][0]-2*w[i];
			}
		}
		int delta=0,pos=0;
		for (int i=last[x];i;i=pre[i])
		{
			if (pp[e[i]]==x)
			{
				if (f[e[i]][0]-2*w[i]>0)
				{
					if (f[e[i]][1]-f[e[i]][0]+w[i]>delta)
					{
						delta=f[e[i]][1]-f[e[i]][0]+w[i];
						pos=e[i];
					}
					f[e[i]][2]=f[x][0]-f[e[i]][0]+2*w[i];
				}
				else
				{
					if (f[e[i]][1]-w[i]>delta)
					{
						delta=f[e[i]][1]-w[i];
						pos=e[i];
					}
					f[e[i]][2]=f[x][0];
				}
			}
		}
		f[x][1]+=delta;
		for (int i=last[x];i;i=pre[i])
		{
			if (pp[e[i]]==x)
			{
				if (e[i]==pos)
				{
					f[e[i]][3]=f[x][1]-f[e[i]][1]+w[i];
					delta=pos=0;
					for (int j=last[x];j;j=pre[j])
					{
						if (pp[e[j]]==x&&e[j]!=e[i])
						{
							if (f[e[j]][0]-2*w[j]>0)
							{
								if (f[e[j]][1]-f[e[j]][0]+w[j]>delta)
								{
									delta=f[e[j]][1]-f[e[j]][0]+w[j];
									pos=e[j];
								}
							}
							else
							{
								if (f[e[j]][1]-w[j]>delta)
								{
									delta=f[e[j]][1]-w[j];
									pos=e[j];
								}
							}
						}
					}
					f[e[i]][3]+=delta;
					pos=0;
				}
				else
				{
					if (f[e[i]][0]-2*w[i]>0) f[e[i]][3]=f[x][1]-f[e[i]][0]+2*w[i];
					else f[e[i]][3]=f[x][1];
				}
			}
		}
}
int ans[1100000];
void dfs2(int x,int fa,int y,int z)
{
	pp[x]=fa;
	ans[x]=max(ans[x],f[x][0]),ans[x]=max(ans[x],f[x][1]);
	ans[x]=max(ans[x],f[x][0]+z),ans[x]=max(ans[x],f[x][1]+y);
	for (int i=last[x];i;i=pre[i])
	{
		if (!pp[e[i]])
		{
			int ny=y,nz=z;
			ny=max(y+f[e[i]][2]-2*w[i],0);
			nz=max(max(z+f[e[i]][2]-w[i],y+f[e[i]][3]-w[i]),0);
			dfs2(e[i],x,ny,nz);
		}
	}		
}
int cas;
char s[110]="npc0.in";
char t[110]="npc0.ans";
int main()
{
	for (int T=9;T<10;T++)
	{
		s[3]=T+'0',t[3]=T+'0';
		freopen(s,"r",stdin);
		freopen(t,"w",stdout);
		scanf("%d",&n);
		num=0;
		for (int i=1;i<=n;i++)
			scanf("%d",&v[i]),last[i]=pp[i]=ans[i]=0;
		for (int i=1;i<n;i++)
		{
			scanf("%d %d %d",&x,&y,&z);
			e[++num]=y,pre[num]=last[x],last[x]=num,w[num]=z;
			e[++num]=x,pre[num]=last[y],last[y]=num,w[num]=z;
		}
		dfs(1,1);
		for (int i=1;i<=n;i++)
			pp[i]=ans[i]=0;
		dfs2(1,1,0,0);
		for (int i=1;i<=n;i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
