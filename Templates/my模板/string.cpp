void getnext()
{	int i,p,h,t;
	q[h=t=1]=0;
	while (h<=t)
	{	p=trie[trie[q[h]].par].next;
		do
		{	if (trie[p].ch[trie[q[h]].chr-'a']&&p!=trie[q[h]].par)
			{	trie[q[h]].next=trie[p].ch[trie[q[h]].chr-'a'];
				break ;
			}
			else p=trie[p].next;
		} while (p);
		if (trie[p].ch[trie[q[h]].chr-'a']&&p!=trie[q[h]].par)
			trie[q[h]].next=trie[p].ch[trie[q[h]].chr-'a'];
		if (q[h])
			add(trie[q[h]].next,q[h]);
		for (i=0;i<26;++i)
			if (trie[q[h]].ch[i])
				q[++t]=trie[q[h]].ch[i];
		++h;
	}
}
//AC Automaton & Fail Tree
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
//Extended KMP
void getnext()
{	int i,j;	
	i=0,j=1;
	next[1]=0;
	while (j<=m)
		if (i==0||st[i]==st[j])
		{	++i,++j;
			next[j]=i;
		}
		else i=next[i];
}
int kmp(char s[],int n)
{	int i,j,ans=0;
	i=j=1;
	while (i<=n&&j<=m)
	{	if (j==0||s[i]==st[j])
			++i,++j;
		else j=next[j];
		if (j>m)
			++ans,j=next[j];
	}
	return ans;
}
//KMP
void init()
{	int i;
	st[1]='#';
	for (i=1;i<=n;++i)
	{	st[i*2+1]='#';
		st[i*2]=t[i];
	}
	n=n*2+1;
	st[0]='%',st[n+1]='$';
}
int manacher()
{	int i,p,ans=0;
	r[1]=0,p=1;
	for (i=2;i<=n;++i)
	{	if (i<=p+r[p])
			r[i]=min(r[2*p-i],p+r[p]-i);
		else r[i]=1;
		while (st[i-r[i]]==st[i+r[i]])
			++r[i];
		--r[i];
		if (i+r[i]>p+r[p])
			p=i;
		ans=max(ans,r[i]);
	}
	return ans;
}
//Manacher
template<typename T>
void radix(int a[],int b[],T s[],int m,int n)
{	int i;
	for (i=0;i<=m;++i)
		h[i]=0;
	for (i=1;i<=n;++i)
		++h[s[a[i]]];
	for (i=1;i<=m;++i)
		h[i]+=h[i-1];
	for (i=n;i>0;--i)
		b[h[s[a[i]]]--]=a[i];
}
void init_sa()
{	int i,j;
	for (i=1;i<=n;++i)
		rank[i]=i;
	radix(rank,sa,st,255,n);
	rank[sa[1]]=1;
	for (i=2;i<=n;++i)
		if (st[sa[i]]!=st[sa[i-1]])
			rank[sa[i]]=rank[sa[i-1]]+1;
		else rank[sa[i]]=rank[sa[i-1]];
	for (i=1;i<=n;i*=2)
	{	for (j=1;j<=n;++j)
		{	a[j]=rank[j];
			if (i+j<=n)
				b[j]=rank[i+j];
			else b[j]=0;
			sa[j]=j;
		}
		radix(sa,rank,b,n,n);
		radix(rank,sa,a,n,n);
		rank[sa[1]]=1;
		for (j=2;j<=n;++j)
			if (a[sa[j]]!=a[sa[j-1]]||b[sa[j]]!=b[sa[j-1]])
				rank[sa[j]]=rank[sa[j-1]]+1;
			else rank[sa[j]]=rank[sa[j-1]];
		if (rank[sa[n]]==n)
			break ;
	}
}
void calc_height()
{	int i,p=0;
	for (i=1;i<=n;++i)
	{	if (p)
			--p;
		if (rank[i]!=1)
			while (st[i+p]==st[sa[rank[i]-1]+p]&&st[i+p]!='|')
				++p;
		height[rank[i]]=p;
	}
}
//Suffix Array

