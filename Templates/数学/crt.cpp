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
