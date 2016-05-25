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
