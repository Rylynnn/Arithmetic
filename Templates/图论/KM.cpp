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
