long double simpson(long double l,long double r,int n)
{
	long double h=(r-l)/(long double)n/2.0;
	long double res=0;
	res+=f(l)+f(r);
	for (int i=1;i<2*n;i++)
		if (i&1) res+=4.0*f(i*h+l);
		else res+=2.0*f(i*h+l);
	res/=6.0*(long double)n;
	res*=(r-l);
	return res;
}
