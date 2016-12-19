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
#include<ctime>

using namespace std;
typedef long long LL;
char s[]="whale0.in";
char t[]="whale0.out";
int n;
LL x;
int main()
{
	for (int T=0;T<3;T++)
	{
		s[5]=T+'0',t[5]=T+'0';
		freopen(s,"w",stdout);
		n=rand()%10+90;
		cout<<n<<endl;
		for (int i=1;i<=n;i++)
		{
			x=rand()%100+300;
			cout<<x;
			if (i!=n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}
