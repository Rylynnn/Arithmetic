inline long long multi_mod(long long a,long long b,long long c)
{	long long ret=0;
	if (a>=c)
		a%=c;
	if (b>=c)
		b%=c;
	while (b)
	{	if (b&1)
		{	ret+=a;
			if (ret>=c)
				ret-=c;
		}
		a<<=1;
		if (a>=c)
			a-=c;
		b>>=1;
	}
	return ret;
}
void ex_gcd(long long a,long long b,long long &x,long long &y)
{	if (b==0)
	{	x=1,y=0;
		return ;
	}
	else 
	{	ex_gcd(b,a%b,y,x);
		y-=x*(a/b);
	}
}
inline long long inverse(long long x)
{	long long ans,y;
	ex_gcd(x,lim,ans,y);
	if (ans<0)
		ans+=lim;
	return ans;
}
inline bool miller_rabin(long long a,long long n)
{	long long d,t;
	if (n==2)
		return true;
	if (n==1||(n&1)==0)
		return false;
	d=n-1;
	while ((d&1)==0)
		d>>=1;
	t=qp(a,d,n);
	while (d!=n-1&&t!=1&&t!=n-1)
	{	t=multi_mod(t,t,n);
		d<<=1;
	}
	return t==n-1||(d&1);
}
inline bool prime_test(long long n)
{	int i;
	for (i=0;i<prime_base_size;++i)
	{	if (prime_base[i]==n)
			return true;
		if (!miller_rabin(prime_base[i],n))
			return false;
	}
	return true;
}
inline long long pollard_rho(long long n,long long c)
{	long long x,y,d;
	int loop_cnt=0;
	x=2,y=2,d=1;
	while (d==1&&loop_cnt<1000)
	{	x=(multi_mod(x,x,n)+c)%n;
		y=(multi_mod(y,y,n)+c)%n;
		y=(multi_mod(y,y,n)+c)%n;
		d=gcd(llabs(x-y),n);
		++loop_cnt;
	}
	return d;
}
void sieve()
{	int i,j;
	phi[1]=1,miu[1]=1;
	for (i=1;i<=n;++i)
	{	if (!h[i])
		{	prime[++pc]=i;
			phi[i]=i-1;
			miu[i]=-1;
		}
		for (j=1;j<=pc&&prime[j]*i<=n;++j)
		{	h[i*prime[j]]=1;
			if (i%prime[j]==0)
			{	phi[i*prime[j]]=phi[i]*prime[j];
				miu[i*prime[j]]=0;
				break ;
			}
			else 
			{	phi[i*prime[j]]=phi[i]*phi[prime[j]];
				miu[i*prime[j]]=-miu[i];
			}
		}
	}
}
LL work(LL n,LL m)
{	LL i,p,ans=0;
	for (i=1;i<=n;i=p+1)
	{	p=min(n/(n/i),m/(m/i));
		ans+=(sum[p]-sum[i-1])*(LL)(n/i)*(m/i);
	}
	return ans;
}
LL crt(LL a[],const int m[],int n)
{	LL Mi,ans=0,x,y,M;
	int i;
	M=1;
	for (i=1;i<=n;++i)
		M*=m[i];
	for (i=1;i<=n;++i)
	{	Mi=M/m[i];
		ex_gcd(m[i],Mi,x,y);
		ans+=y*Mi*a[i];
		ans%=M;
	}
	return (ans+M)%M;
}
pair<LL,LL> fact(LL n)
{	if (n<=1)
		return make_pair(1LL,0LL);
	pair<LL,LL> ret;
	LL m=n/lim,s,x,i;
	ret=fact(m);
	ret.second+=m*ep;
	for (i=lim*m+1;i<=n;++i)
	{	x=i;
		while (x%p==0)
			++ret.second,x/=p;
		ret.first=ret.first*x%lim;
	}
	s=1;
	for (i=1;i<lim;++i)
	{	x=i;
		while (x%p==0)
			ret.second+=m,x/=p;
		s=s*x%lim;
	}
	s=qp(s,m);
	ret.first=ret.first*s%lim;
	return ret;
}
LL comb(LL k,LL n)
{	pair<LL,LL> a,b,c,ret;
	LL cnt=0;
	a=fact(n);
	b=fact(k);
	c=fact(n-k);
	cnt+=a.second;
	cnt-=b.second;
	cnt-=c.second;
	if (cnt>=ep)
		return 0;
	else return a.first*qp(p,cnt)%lim*qp((LL)b.first*c.first%lim,lim/p*(p-1)-1)%lim;
}
LL work()
{	int i,x=lim;
	for (i=2;i*i<=x;++i)
		if (x%i==0)
		{	sdiv[++dc]=i;
			val[dc]=1;
			while (x%i==0)
				x/=i,++cnt[dc],val[dc]*=i;
		}
	if (x>1)
		sdiv[++dc]=x,cnt[dc]=1,val[dc]=x;
	for (i=1;i<=dc;++i)
	{	lim=val[i];
		p=sdiv[i];
		ep=cnt[i];
		res[i]=comb(k,n);
	}
	return crt(res,val,dc);
}
//Binomial modulo lim
inline long long c(long long m,long long n)
{	return fact[m]*qp(fact[n]*fact[m-n]%lim,lim-2)%lim;
}
long long lucas(long long m,long long n)
{	long long ans=1;
	int i;
	while (m!=0)
	{	if (m%lim<n%lim)
			return 0;
		ans*=c(m%lim,n%lim);
		ans%=lim;
		m/=lim,n/=lim;
	}
	return ans%lim;
}
//Lucas
