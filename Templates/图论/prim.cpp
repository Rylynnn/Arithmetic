intPrim()
{
	memset(v,0,sizeof v);
	for (int i=1;i<=N;i++)  dis[i]=INF;
	dis[1]=0;
	int ans=0;
	for (int i=1;i<=N;i++)
	{
		int mark=-1;
		for (int j=1;j<=N;j++)
		  if (!v[j])
		  {
				if (mark==-1) mark=j;
				      else  if (dis[j]<dis[mark]) mark=j;
				if (mark==-1) break;
				v[mark]=1;
				ans+=dis[mark];
				for (int j=0;j<g[mark].size();j++)
				  if (!v[g[mark][j].first])
				  {
						int x=g[mark][j].first;
						dis[x]=min(dis[x],g[mark][j].second);
				  }
		  }
   }
   return ans;
}			
