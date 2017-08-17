int n,m;
int en;
int st,ed;
int dis[maxn] ;
int que[9999999];
struct edge
{
	int to,c,next;
};
edge e[9999999];
int head[maxn];
void add(int a,int b,int c)
{
	e[en].to=b;
	e[en].c=c;
	e[en].next=head[a];
	head[a]=en++;
	e[en].to=a;
	e[en].c=0;
	e[en].next=head[b];
	head[b]=en++;
}
int bfs()
{
    memset(dis,-1,sizeof(dis));
    dis[st]=0;
    int front=0,rear=0;
    que[rear++]=st;
    while(front<rear)
    {
        int j=que[front++];
        for(int k=head[j];k!=-1;k=e[k].next)
        {
            int i=e[k].to;
			if(dis[i]==-1&&e[k].c)
            {
                dis[i] = dis[j]+ 1 ;
                que[rear++]=i;
                if(i==ed) return true;
            }
        }
    }
    return false;
}
int dfs(int x,int mx)
{
    int i,a;
    if(x==ed) return mx ;
    int ret=0;
    for(int k=head[x];k!=-1&&ret<mx;k=e[k].next)
    {
        if(e[k].c&&dis[e[k].to]==dis[x]+1)
        {
            int dd=dfs(e[k].to,min(e[k].c,mx-ret));
            e[k].c-=dd;
            e[k^1].c+=dd;
            ret+=dd;
        }
    }
    if(!ret) dis[x]=-1;
    return ret;
}
int dinic()
{
    int tmp=0;
    int maxflow=0;
    while(bfs())
    {
        while(tmp=dfs(st,INF)) maxflow+=tmp;
    }
    return maxflow;
}
