#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

#define LL long long

const int maxn=1000100;
bool valid[maxn];
int prim[maxn],pr[maxn];
int primm=0,c;   //c为n质因子的个数 
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

void cal(LL n)
{
	LL t=n,a;
	c=0;
	for (int i=0;prim[i]*prim[i]<=n;i++)
	{
		if (n%prim[i]==0)
		{
			pr[c]=prim[i];
			while (n%prim[i]==0) n/=prim[i];
			c++;
		}
	}
	if (n>1)
	{
		pr[c]=n;
		c++;
	}
}
LL quick_mod(LL a,LL b,LL m)
{
	LL ans=1;
	a%=m;
	while (b)
	{
		if (b&1)
		{
			ans=ans*a%m;
			b--;
		}
		b>>=1;
		a=a*a%m;
	}
	return ans;
}

int main()
{
	LL P,t,g,root;
	getPrime(maxn-1,primm,prim);
	while (cin>>P)
	{
		cal(P-1);
		for (g=2;g<P;g++)
		{
			bool flag=true;
			for (int i=0;i<c;i++)
			{
				t=(P-1)/pr[i];
				if (quick_mod(g,t,P)==1)
				{
					flag=false;
					break;
				}
			}
			if (flag)
			{
				root=g;
				cout<<root<<endl;
			}
		}
	}
	return 0;
}
