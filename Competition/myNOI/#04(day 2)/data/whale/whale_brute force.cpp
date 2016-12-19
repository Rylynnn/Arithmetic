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
LL sum[210000];
LL ans,x;
int main()
{
	for (int i=1;i<=200000;i++)
	{
		sum[i]=sum[i-1];
		for (int j=1;j*j<=i;j++)
		{
			if (i%j==0)
			{
				sum[i]=(sum[i]+j)%mod;
				if (j*j!=i) sum[i]=(sum[i]+i/j)%mod;
			}
		}
	}
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		ans=(ans+sum[x])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
		
		
