typedef long long LL;
const int maxn=200000;
const LL P=1004535809; //P=C*2^k+1，P是质数
const LL g=3; //P的原根
int N,na,nb;
int a[maxn*2],b[maxn*2],W[2][maxn*2],rev[maxn*2];

LL Pow(LL a,int b)
{
	LL c=1;
	for (;b; b>>=1,a=a*a%P) if (b&1) c=c*a%P;
	return c;
}
void NTT(int*a,int f)
{
	for (int i=0;i<N;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int i=1;i<N;i<<=1)
		for (int j=0,t=N/(i<<1);j<N;j+=i<<1)
			for (int k=0,l=0,x,y;k<i;k++,l+=t) x=(LL)W[f][l]*a[j+k+i]%P,y=a[j+k],a[j+k]=(y+x)%P,a[j+k+i]=(y-x+P)%P;
	if (f) for (int i=0,x=Pow(N,P-2);i<N;i++) a[i]=(LL)a[i]*x%P;
}
void change()
{
	for (int i=0;i<N;i++)
	{
		int x=i,y=0;
		for (int k=1; k<N; x>>=1,k<<=1) (y<<=1)|=x&1;
		rev[i]=y;
	}
}
int main()
{
	for (N=1; N<na||N<nb; N<<=1); N<<=1;
	for (int i=na;i<N;i++)
	  a[i]=b[i]=0;
	W[0][0]=W[1][0]=1;
	for (int i=1,x=Pow(g,(P-1)/N),y=Pow(x,P-2); i<N; i++) 
	    W[0][i]=(LL)x*W[0][i-1]%P,W[1][i]=(LL)y*W[1][i-1]%P;
	change();
	NTT(a,0),NTT(b,0);
	for (int i=0;i<N;i++) a[i]=(LL)a[i]*b[i]%P;
	NTT(a,1);
}

