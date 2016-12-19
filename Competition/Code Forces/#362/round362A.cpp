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
map<LL,LL> S;
int n;
LL u,v,x;
LL ans;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		if (op==1)
		{
			cin>>u>>v>>x;
			S[u]+=x;
			S[v]+=x;
			while (u!=v)
			{
				if (u>v) u/=2,S[u]+=x;
				else v/=2,S[v]+=x;
			}
			S[v]-=2*x;
		}
		else
		{
			cin>>u>>v;
			ans=S[u]+S[v];
			while (u!=v)
			{
				if (u>v) u/=2,ans+=S[u];
				else v/=2,ans+=S[v];
			}
			ans-=2*S[u];
			cout<<ans<<endl;
		} 
	}
	return 0;
}
