#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>

using namespace std;
typedef long long LL;
LL m,p,f[2][1100];
LL ans,S[1100][1100],a[1100],b[1100];
int n,x;
int v[110000];
int main()
{
	freopen("sunshine.in","r",stdin);
	freopen("sunshine.out","w",stdout);
	ans=1,S[0][0]=a[0]=b[0]=1;
	cin>>n>>m>>p;
	for (LL i=1;i<1100;i++)
	{
		for (LL j=1;j<=i;j++)
			S[i][j]=(S[i-1][j-1]+(j-1LL)*S[i-1][j])%p;
		a[i]=(a[i-1]*(m-i+1LL))%p;
		b[i]=(b[i-1]*i)%p;
	}
	for (int i=1;i<=n;i++)
	{
		cin>>v[i]; 
		for (int j=1;j<=min((LL)v[i],m);j++)
			f[i&1][j]=(((ans*a[j]-f[~i&1][j]*b[j])%p+p)*S[v[i]][j])%p;
		ans=0;
		for (int j=0;j<v[i]+1;j++)
			ans=(ans+f[i&1][j])%p;
		//ans=accumulate(f[i&1],f[i&1]+v[i]+1,0LL)%p; 
		fill_n(f[~i&1],v[i-1]+1,0);
	}
	cout<<ans<<endl;
	return 0;
}
