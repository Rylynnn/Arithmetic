LL inv(LL a,LL n)
{
	LL xx,yy,d=extended_gcd(a,n,xx,yy);
	return (xx%n+n)%n;
}
