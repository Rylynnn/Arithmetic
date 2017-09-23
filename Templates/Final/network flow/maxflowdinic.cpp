int ed,st;
int num=1,d[N],now[N];
int e[M],pre[M],last[N],f[M];
void insert(int x,int y,int z)
{
	e[++num]=y,f[num]=z,pre[num]=last[x],last[x]=num;
	e[++num]=x,f[num]=0,pre[num]=last[y],last[y]=num;
}
queue<int> q;
bool bfs()
{
    memset(d,-1,sizeof(d));
    d[st]=0;
	q.push(st);
    while(!q.empty())
    {
        int now=q.front();
        for (int i=last[now];i;i=pre[i])
            if(f[i]&&d[e[i]]==-1)
            {
                d[e[i]]=d[now]+1;
                q.push(e[i]); 
            }
        q.pop();
    }
    if(d[ed]==-1)return 0;
	return 1;
}
int dfs(int x,int incf)
{
    if(x==ed)return incf;
    int flow=0,w;
    for (int i=now[x];i;i=pre[i])
        if(f[i]&&d[e[i]]==d[x]+1)
        {
			w=dfs(e[i],min(incf-flow,f[i]));
            f[i]-=w,f[i^1]+=w;
            flow+=w;
            if (f[i]) now[x]=i;
			if(flow==incf) return incf;
        }
    if(!flow) d[x]=-1;
    return flow;
}
int dinic()
{
	int maxflow=0;
	while(bfs())
	{
		for (int i=st;i<=ed;i++)
			now[i]=last[i];	
		maxflow+=dfs(st,1e9);
	}
	return maxflow;	
}
