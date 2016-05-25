void dfs(int x)
{	int  i;
	dfn[x]=++tstamp;
	pos[dfn[x]]=x;
	for (i=0;i<e[x].size();++i)
		if (!dfn[e[x][i]])
		{	par[e[x][i]]=x;
			dfs(e[x][i]);
		}
}
int find(int x)
{	if (f[x]==0)
		return x;
	int y=find(f[x]);
	if (semi[dlink[x]]>semi[dlink[f[x]]])
		dlink[x]=dlink[f[x]];
	return f[x]=y;
}
void tarjan()
{	int i,x,y,z;
	for (i=1;i<=n;++i)
		semi[i]=dlink[i]=i;
	for (y=n;y>1;--y)
	{	x=dfn[par[pos[y]]];
		for (i=0;i<pre[pos[y]].size();++i)
		{	z=dfn[pre[pos[y]][i]];
			find(z);
			semi[y]=min(semi[y],semi[dlink[z]]);
		}
		dom[semi[y]].push_back(y);
		f[y]=x;
		for (i=0;i<dom[x].size();++i)
		{	z=dom[x][i];
			find(z);
			if (semi[dlink[z]]<x)
				idom[z]=dlink[z];
			else idom[z]=x;
		}
		dom[x].clear();
	}
	for (i=2;i<=n;++i)
	{	if (idom[i]!=semi[i])
			idom[i]=idom[idom[i]];
		dom[idom[i]].push_back(i);
	}
	idom[1]=0;
}
