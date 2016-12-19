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
int v[1100000];
char s[110]="sunshine0.in";
char t[110]="sunshine0.out";
int main()
{
	for (int T=0;T<10;T++)
	{
		s[8]=T+'0',t[8]=T+'0';
		freopen(s,"r",stdin);
		freopen(t,"w",stdout);
		ans=1;
		cin>>n>>m>>p;
		memset(f,0,sizeof(f));
		S[0][0]=a[0]=b[0]=1;
		for (LL i=1;i<=1000;i++)
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
			ans=accumulate(f[i&1],f[i&1]+v[i]+1,0LL)%p; 
			fill_n(f[~i&1],v[i-1]+1,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
