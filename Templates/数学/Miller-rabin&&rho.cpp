bool test(int n,int a,int d)
{
	if (n==2) return true;
	if (n==a) return true;
	if ((n&1)==0) return false;
	while (!(d&1)) d=d>>1;
	int t=pow_mod(a,d,n);
	while ((d!=n-1)&&(t!=1)&&(t!=n-1))
	{
		t=(long long) t*t%n;
		d=d<<1;
    }
    return(t==n-1||(d&1)==1);
}

bool isPrime(int n)
{
	if (n<2) return false;
	int a[3]={2,3,61};
	for (int i=0;i<=2;i++)
	  if (!test(n,a[i],n-1)) return false;
	return true;
}

void rho(LL n)
{
	int flag=0;
	while (true)
	{
		LL c=rand()%n+1;
		LL x=rand()%n+1;
		LL y=x;
		if (isPrime(n))
		{
			num++;
			a[num]=n;
			return;
		}
		LL k=2;
		LL i=0;
		while (true)
		{
			i++;
			LL d=gcd(n+y-x,n);
			if (d>1&&d<n)
			{
				flag=1;
				if (isPrime(d))
				{
					num++;
					a[num]=d;
				}
				else rho(d);
				d=n/d;
				if (isPrime(d))
				{
					num++;
					a[num]=d;
				}
				else rho(d);
			}
			if (i==k)
			{
				y=x;
				k*=2;
			}
			x=(pow_mod(x,x,n)+n-c)%n;
			if (y==x) break;
		}
	}
}
				
