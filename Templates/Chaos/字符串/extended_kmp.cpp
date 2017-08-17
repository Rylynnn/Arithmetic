void getnext()
{   int i,j,k=2,p,l;
	next[1]=n;
	next[2]=n-1;
	for (i=1;i<n;++i)
		if (a[i]!=a[i+1])
		{	next[2]=i-1;
			break ;
		}
	for (i=3;i<=n;++i)
	{	p=k+next[k]-1;
		if (i+next[i-k+1]<=p)
			next[i]=next[i-k+1];
		else 
		{	j=max(p-i+1,0);
			while (i+j<=n&&a[i+j]==a[j+1])
				++j;
			next[i]=j;
			k=i;
		}
	}
}
void ex_kmp()
{	int l,i,j,k=1,p;
	l=min(n,m);
	ex[1]=l;
	for (i=1;i<=l;++i)
		if (a[i]!=b[i])
		{	ex[1]=i-1;
			break ;
		}
	for (i=2;i<=m;++i)
	{	p=k+ex[k]-1;
		if (i+next[i-k+1]<=p)
			ex[i]=next[i-k+1];
		else 
		{	j=max(p-i+1,0);
			while (i+j<=m&&j<=n&&b[i+j]==a[j+1])
				++j;
			ex[i]=j,k=i;
		}
	}
}
