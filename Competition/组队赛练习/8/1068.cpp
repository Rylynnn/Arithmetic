#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>

using namespace std;
typedef long long LL;
int a,b,k;
LL m[11000],f[11000];
LL ans;
int flag=0;
int cal(LL num)
{
	int i,j,k;
	LL ans;
	if(m[a-1]*f[b-1]<=num)
		return 0;
	j=b-1;
	ans=0;
	for(i=0;i<a;i++)
	{
		for(;j>=0 &&m[i]*f[j]>num;j--);
			ans+=b-1-j;
	}
	return ans;
}
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>a>>b>>k;
		for (int i=0;i<a;i++)
			cin>>m[i];
		for (int i=0;i<b;i++)
			cin>>f[i];
		sort(m,m+a);
		sort(f,f+b);
		LL l=1,r=m[a-1]*f[b-1];
		while(l<=r)
		{
			LL mid=(l+r)>>1;
			LL tmp =cal(mid);
			if(tmp>=k)
				l=mid+1;
			else
				r=mid-1;
		}
		cout<<r+1<<endl;
	}
	return 0;
}
