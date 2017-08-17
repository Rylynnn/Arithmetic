LL mod,a[110000],b[110000];
int n,m,v[110000],p[110000],s[100],tot,num;
struct divi
{
	int p,c,pc;
}w[110000];
void prepare()
{
	int cnt=0;
	for (int i=2;i<=100000;i++)
		if (!v[i])
		{
			p[++cnt]=i;
			for (int j=i;j<=100000;j+=i)
				v[j]=1;
		}
	num=0;
	LL x=mod;
	for (int i=1;i<=cnt;i++)
	{
		if (x<=1) break;
		if (x%p[i]) continue;
		w[++num].p=p[i];
		w[num].pc=1;
		while (x%p[i]==0)
			w[num].c++,x/=p[i],w[num].pc*=p[i];
		b[num]=w[num].pc;
	}
}
LL pow_mod(LL a,LL i,LL n)
{
	if (i==0) return 1%n;
	LL temp=pow_mod(a,i>>1,n);
    temp=temp*temp%n;
    if (i&1) temp=(LL) temp*a%n;
    return temp;
}
LL extended_gcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        LL r=extended_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
LL inv(LL a,LL n)
{
	LL xx,yy,d=extended_gcd(a,n,xx,yy);
	return (xx%n+n)%n;
}
pa fac(int k,LL n)
{
	if (n==0) return mp(0,1);
	int x=n/w[k].p,y=n/w[k].pc;
	LL ans=1;
	if (y)
	{
		for (int i=2;i<w[k].pc;i++)
			if (i%w[k].p!=0)
				ans=ans*1LL*i%w[k].pc;
	    ans=pow_mod(ans,y,w[k].pc);
	}
	for (int i=y*w[k].pc+1;i<=n;i++)
		if (i%w[k].p!=0)
			ans=ans*1LL*i%mod;
	pa p=fac(k,x);
	return mp(x+p.fi,ans*p.se%mod);
}
LL get(int k,LL n,LL m)
{
	if (n<m) return 0;
	pa a=fac(k,n),b=fac(k,m),c=fac(k,n-m);
	LL mod=w[k].pc;
	return pow_mod(w[k].p,a.fi-b.fi-c.fi,mod)*
		   a.se%mod*inv(b.se,mod)%mod*
		   inv(c.se,mod)%mod; 
}
LL crt(LL a[],LL b[],int num,LL mod)
{
	LL M=mod,d,y,x=0;
	for (int i=1;i<=num;i++)
	{
		LL r=M/b[i];
		d=extended_gcd(w[i].pc,r,d,y);
		x=(x+r*y*a[i])%M;
	}
	return (x+M)%M;
}
LL C(int n,int m)
{
	for (int i=1;i<=num;i++)
		a[i]=get(i,n,m);
	return (crt(a,b,num,mod))%mod;
}
