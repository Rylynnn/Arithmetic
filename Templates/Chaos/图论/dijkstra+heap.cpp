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
