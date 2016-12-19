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
const LL mod=1e9+7;
int n;
LL ans,x;
LL last;
LL cc(LL x,LL y)
{
	LL l=x/(y+1)+1,r=x/y;
	last=r;
	LL a=(r+l)*(r-l+1)/2;
	return a*y%mod;
}
LL cal(LL x)
{
	LL res=0;
	last=0;
	while (last<x)
	{
		last++;
		LL i=x/last;
		res=(res+cc(x,i))%mod;
	}
	return res;
}
int main()
{
	freopen("whale.in","r",stdin);
	freopen("whale.out","w",stdout);
	ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		ans=(ans+cal(x))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
		
		
