#define maxn 1000000
bool valid[maxn];
int primm;
LL prim[maxn];
void getPrime(int n)
{
	memset(valid,true,sizeof(valid));
	for (int i=2;i<=n;i++)
	{
		if (valid[i])
		{
			primm++;
			prim[primm]=i;
			for (int j=2;j<=n/i;j++)
			  valid[i*j]=0;
		}
	}
}
