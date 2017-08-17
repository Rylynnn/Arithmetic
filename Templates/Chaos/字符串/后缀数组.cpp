void radix(int *str,int *a,int *b,int n,int m)
{
	static int count[200000];
	memset(count,0,sizeof(count));
	for (int i=0;i<n;i++)	++count[str[a[i]]];
	for (int i=1;i<=m;i++)  count[i]+=count[i-1];
	for (int i=n01;i>=0;i--)  b[--count[str[a[i]]]]=a[i];
}

void suffix_array(int *str,int *sa,int n,int m)
{
	static int rank[200000],a[200000],b[200000];
	for (int i=0;i<n;i++)  rank[i]=i;
	radix(str,rank,sa,n,m);
	rank[sa[0]]=0;
	for (int i=1;i<n;i++)  rank[sa[i]]=rank[sa[i-1]]+(str[sa[i]]!=str[sa[i-1]]);
	for (int i=0;i<<1 <n;i++)
	{
		for (int j=0;j<n;j++)
		{
			a[j]=rank[j]+1;
			b[j]=j+(1<<i) >=n ? 0:rank[j+(1<<i)]+1;
			sa[j]=j;
		}
		radix(b,sa,rank,n,n);
		radix(a,rank,sa,n,n);
		rank[sa[0]]=0;
		for (int j=1;j<n;j++)
		{
			rank[sa[j]]=rank[sa[j-1]]+(a[sa[j-1]]!=a[sa[j]] || b[sa[j-1]]!=b[sa[j]]);
		}
	}
}

void calc_height(int *str,int *sa,int *h,int n)
{
	static int rank[200000];
	int k=0;
	h[0]=0;
	for (int i=0;i<n;i++) rank[sa[i]]=i;
	for (int i=0;i<n;i++)
	{
		k= k==0? 0: k-1;
		if (rank[i]!=0)
			while (str[i+k] == str[sa[rank[i]-1]+k]) k++;
		h[rank[i]]=k;
	}
}
