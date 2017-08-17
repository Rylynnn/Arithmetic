struct node
{	int v;
	long long d;
};
void swap(int x,int y)
{	struct node t;
	t=heap[x],heap[x]=heap[y],heap[y]=t;
    pos[heap[x].v]=x,pos[heap[y].v]=y;
}
void heapify(int k)
{   int i,j;
    i=k,j=2*i;
    while(j<=hl)
    {   if (j+1<=hl&&heap[j+1].d<heap[j].d)
            ++j;
	    if (heap[i].d<heap[j].d)
	        break ;
        else swap(i,j),i=j,j=i*2;
    }
}
void upward(int x)
{   int i;
    i=x;
    while (i>0)
    {   if (heap[i].d<heap[i/2].d)
            swap(i,i/2),i/=2;
        else break ;
    }
}
void del(int x)
{	swap(x,hl);
	--hl;
	heapify(1);
}
void dijkstra(long long dis[],int src)
{	int i,u;
	for (i=1;i<=n;++i)
	{	heap[i].d=INF;
		heap[i].v=i;
		pos[i]=i;
	}
	hl=n;
	swap(src,1);
	heap[1].d=0;
	while (hl>0)
	{	u=heap[1].v;
		del(1);
		for (i=last[u];i!=0;i=pre[i])
			if (pos[e[i]]<=hl&&heap[pos[u]].d+w[i]<heap[pos[e[i]]].d)
			{	heap[pos[e[i]]].d=heap[pos[u]].d+w[i];
				upward(pos[e[i]]);
			}
	}
	for (i=1;i<=n;++i)
		dis[i]=heap[pos[i]].d;
}
//Dijkstra
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int dijkstra()
{	int i,u;
	memset(in,0,sizeof(in));
	for (i=1;i<=n;++i)
		dis[i]=INF;
	dis[1]=0;
	for (i=1;i<=n;++i)
		q.push(make_pair(dis[i],i));
	while (!q.empty())
	{	u=q.top().second;
		q.pop();
		if (in[u])
			continue ;
		in[u]=1;
		for (i=last[u];i!=0;i=pre[i])
			if (dis[e[i]]>dis[u]+w[i])
			{	dis[e[i]]=dis[u]+w[i];
				q.push(make_pair(dis[e[i]],e[i]));
			}
	}
	return dis[n];
}
void tarjan(int x,int par)//BCC & Cut Vertex
{	int i,dc=0;
	dfn[x]=low[x]=++T;
	st.push(x);
	for (i=last[x];i!=0;i=pre[i])
		if (dfn[e[i]]==0)
		{	++dc;
			tarjan(e[i],x);
			low[x]=min(low[x],low[e[i]]);
			if (low[e[i]]>=dfn[x])
			{	cut[x]=1;
				++bcn;
				while (!st.empty()&&st.top()!=e[i])
				{	bcc[bcn].push_back(st.top());
					st.pop();
				}
				bcc[bcn].push_back(e[i]);
				st.pop();
				bcc[bcn].push_back(x);
			}
		}
		else low[x]=min(low[x],dfn[e[i]]);
	if (par==0&&dc==1)
		cut[x]=0;
}
void tarjan(int x)//Cut Edge
{	int i;
	low[x]=dfn[x]=++T;
	for (i=last[x];i!=0;i=pre[i])
		if (dfn[e[i]]==0)
		{	epar[e[i]]=((i-1)>>1)+1;
			tarjan(e[i]);
			low[x]=min(low[x],low[e[i]]);
		}
		else 
			if (epar[x]!=(((i-1)>>1)+1))
				low[x]=min(low[x],dfn[e[i]]);
	if (low[x]==dfn[x])
		cut[epar[x]]=1;
}
void tarjan(int x)//SCC
{	int i;
	dfn[x]=low[x]=++T;
	st.push(x);
	instack[x]=1;
	for (i=last[x];i!=0;i=pre[i])
		if (dfn[e[i]]==0)
		{	tarjan(e[i]);
			low[x]=min(low[x],low[e[i]]);
		}
		else 
			if (instack[e[i]])
				low[x]=min(low[x],dfn[e[i]]);
	if (low[x]==dfn[x])
	{	++scc_cnt;
		while (!st.empty()&&st.top()!=x)
		{	scc[st.top()]=scc_cnt;
			instack[st.top()]=0;
			st.pop();
		}
		st.pop();
		scc[x]=scc_cnt;
		instack[x]=0;
	}
}
#define targ(p,x) (qr[p].first==x?qr[p].second:qr[p].first)
void tarjan(int u)//LCA
{	int i;
	for (i=last[u];i!=0;i=pre[i])
	{	tarjan(e[i]);
		f[find(e[i])]=u;
	}
	c[u]=1;
	for (i=0;i<inq[u].size();++i)
		if (c[targ(inq[u][i],u)]&&res[inq[u][i]]==-1)
			res[inq[u][i]]=trie[find(targ(inq[u][i],u))].cod;
}
int findpath(int x)
{	int i;
	lh[x]=1;
	for (i=1;i<=n;++i)
		if (lx[x]+ly[i]==g[x][i]&&rh[i]==0)
		{	rh[i]=1;
			if (match[i]==0||findpath(match[i]))
			{	match[i]=x;
				return 1;
			}
		}
		else slack[i]=min(slack[i],lx[x]+ly[i]-g[x][i]);
	return 0;
}
void update()
{	int i,j,delta=INF;
	for (i=1;i<=n;++i)
		if (!rh[i])
			delta=min(delta,slack[i]);
	for (i=1;i<=n;++i)
	{	if (lh[i])
			lx[i]-=delta;
		if (rh[i])
			ly[i]+=delta;
	}
}
int km()
{	int i,j,ans=0;
	for (i=1;i<=n;++i)
	{	lx[i]=-INF;
		for (j=1;j<=n;++j)
			lx[i]=max(lx[i],g[i][j]);
	}
	for (i=1;i<=n;++i)
	{	fill(slack+1,slack+n+1,INF);
		while (1)
		{	memset(lh,0,sizeof(lh));
			memset(rh,0,sizeof(rh));
			if (findpath(i))
				break ;
			else update();
		}
	}
	for (i=1;i<=n;++i)
		ans+=g[match[i]][i];
	return -ans;
}
//KM
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
//Dominator Tree
void init_dist()
{	int i,h,t;
	q[h=t=1]=dest;
	d[dest]=1;
	while (h<=t)
	{	for (i=last[q[h]];i!=0;i=pre[i])
			if (d[e[i]]==0)
			{	d[e[i]]=d[q[h]]+1;
				++gap[d[e[i]]];
				q[++t]=e[i];
			}
		++h;
	}
}
int update()
{	int i,delta=INF;
	for (i=dest;i!=src;i=e[rev(r[i])])
		delta=min(delta,f[r[i]]);
	for (i=dest;i!=src;i=e[rev(r[i])])
	{	f[r[i]]-=delta;
		f[rev(r[i])]+=delta;
	}
	return delta;
}
void relabel(int& p)
{	int i,t=n+3;
	for (i=last[p];i!=0;i=pre[i])
		if (f[i]>0)
			t=min(t,d[e[i]]+1);
	--gap[d[p]];
	++gap[t];
	d[p]=t;
	if (p!=src)
		p=e[rev(r[p])];
}
int sap()
{	int i,j,ans;
	init_dist();
	memcpy(cur,last,sizeof(cur));
	i=src,ans=0;
	while (d[src]<n)
	{	if (i==dest)
		{	ans+=update();
			i=src;
		}
		for (j=cur[i];j!=0;j=pre[j])
			if (f[j]>0&&d[e[j]]+1==d[i])
			{	cur[i]=j;
				r[e[j]]=j;
				i=e[j];
				break ;
			}
		if (j==0)
		{	if (gap[d[i]]==1)
				break ;
			cur[i]=last[i];
			relabel(i);
		}
	}
	return ans;
}
//ISAP
bool find_ring()
{	int i,j,k,c=0;
	memset(bel,0,sizeof(bel));
	memset(pre,0,sizeof(pre));
	memset(h,0,sizeof(h));
	fill(min_adv+1,min_adv+n+1,INF);
	for (i=1;i<=m;++i)
		if (e[i].w<min_adv[e[i].v]&&e[i].u!=e[i].v)
		{	pre[e[i].v]=e[i].u;
			min_adv[e[i].v]=e[i].w;
		}
	min_adv[root]=0;
	for (i=1;i<=n;++i)
		if (min_adv[i]>INF-2)
			throw(int(0));
	for (i=1;i<=n;++i)
	{	ans+=min_adv[i];
		for (j=i;h[j]!=i&&bel[j]==0&&j!=root;j=pre[j])
			h[j]=i;
		if (j!=root&&bel[j]==0)
		{	bel[j]=++c;
			for (k=pre[j];k!=j;k=pre[k])
				bel[k]=c;
		}
	}
	if (c==0)
		return false;
	for (i=1;i<=n;++i)
		if (bel[i]==0)
			bel[i]=++c;
	n=c;
	return true;
}
double edmonds()
{	double dv;
	int i;
	root=1;
	ans=0;
	while (find_ring())
	{	for (i=1;i<=m;++i)
		{	dv=min_adv[e[i].v];
			e[i].u=bel[e[i].u];
			e[i].v=bel[e[i].v];
			if (e[i].u!=e[i].v)
				e[i].w-=dv;
		}
		root=bel[root];
	}
	return ans;
}
//Minimum arborescence
