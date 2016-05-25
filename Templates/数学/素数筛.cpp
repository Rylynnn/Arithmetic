#define maxn 1000000
bool valid[maxn];
void getPrime(int n,int &tot,int ans[maxn])    //n为筛素数的范围,tot为素数总数,ans[]为prim数组 
{
	memset(valid,true,sizeof(valid));
	for (int i=2;i<=n;i++)
	{
		if (valid[i])
		{
			tot++;
			ans[tot]=i;
			for (int j=2;j<=n/i;j++)
			  valid[i*j]=0;
		}
	}
}
