const int N=4100;
const int M=1100000;
int e[M],f[M],w[M],pre[M],last[N];
int d[N],dd[N],pp[N],now[N];
int n,m;
int num=1,st,ed,maxflow,flag;
LL ans;
queue<int> q;
void insert(int x,int y,int z,int c)
{
	e[++num]=y,f[num]=z,w[num]=c,pre[num]=last[x],last[x]=num;
	e[++num]=x,f[num]=0,w[num]=-c,pre[num]=last[y],last[y]=num;
}
bool spfa()
{	
	for (int i=st;i<=ed;i++)
		d[i]=dd[i]=1e9,pp[i]=0;
	q.push(st);
	d[st]=dd[st]=0;pp[st]=1;
	while (!q.empty())
	{
		int x=q.front();
		for (int i=last[x];i;i=pre[i])
		{
			if (!f[i]) continue;
			int y=e[i];
			if (d[y]>d[x]+w[i]||d[y]==d[x]+w[i]&&dd[y]>dd[x]+1)
			{
				d[y]=d[x]+w[i];
				dd[y]=dd[x]+1;
				if (!pp[y]) pp[y]=1,q.push(y);
			}
		}
		pp[x]=0;
		q.pop();
	}
	if (d[ed]==1e9) return false;
	return true;
}
int dfs(int x,int incf)
{
    if(x==ed)return incf;
    int flow=0,ww;
    for (int i=now[x];i;i=pre[i])
        if(f[i]&&dd[e[i]]==dd[x]+1&&d[e[i]]==d[x]+w[i])
        {
			ww=dfs(e[i],min(incf-flow,f[i]));
            f[i]-=ww,f[i^1]+=ww;
            flow+=ww;
            ans+=(LL)ww*(LL)w[i];
            if (f[i]) now[x]=i;
			if(flow==incf) return incf;
        }
    if(!flow) dd[x]=-1;
    return flow;
}
void dinic()
{
	while(spfa()) 
	{
		for (int i=st;i<=ed;i++)
			now[i]=last[i];
		maxflow+=dfs(st,1e9);
	}
}
