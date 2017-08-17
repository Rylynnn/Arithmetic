const int mod=9973;
const int MAXN=20;
const int MAXM=20;
struct Matrix
{
	int n,m;
	int a[MAXN][MAXM];
	void clear()
	{
		n=m=0;
		memset(a,0,sizeof(a));
	}
	Matrix operator +(const Matrix &b) const
	{
		Matrix tmp;
		tmp.n=n; tmp.m=m;
		for (int i=0;i<n;i++)
		  for (int j=0;j<m;j++)
		    tmp.a[i][j]=a[i][j]+b.a[i][j];
	    return tmp;
	}
	Matrix operator -(const Matrix &b) const
	{
		Matrix tmp;
		tmp.n=n; tmp.m=m;
		for (int i=0;i<n;i++)
		  for (int j=0;j<m;j++)
		    tmp.a[i][j]=a[i][j]-b.a[i][j];
		return tmp;
    }
    Matrix operator *(const Matrix &b) const
    {
		Matrix tmp;
		tmp.clear();
		tmp.n=n;
		tmp.m=b.m;
		for (int i=0;i<n;i++)
		  for (int j=0;j<b.m;j++)
		    for (int k=0;k<m;k++)
		      tmp.a[i][j]+=a[i][k]*b.a[k][j];
		return tmp;
    }
    Matrix operator %(const int b) const
    {
		Matrix tmp;
		tmp.clear();
		tmp.n=n;
		tmp.m=m;
		for (int i=0;i<n;i++)
		  for (int j=0;j<m;j++)
		      tmp.a[i][j]=((abs(a[i][j])/b+1)*b+a[i][j])%b;
		return tmp;
    }
};
Matrix pow_mod(Matrix a,LL i,LL n)
{
	if (i==0)
	{
		Matrix b;
		b.n=b.m=a.n;
		for (int j=0;j<b.n;j++)
		    for (int k=0;k<b.n;k++)
		        if (j!=k) b.a[j][k]=0;
		        else b.a[j][k]=1;
		return b;
	}
	Matrix temp=pow_mod(a,i>>1,n);
	temp=temp*temp%n;
	if (i&1) temp=temp*a%n;
	return temp;
}
