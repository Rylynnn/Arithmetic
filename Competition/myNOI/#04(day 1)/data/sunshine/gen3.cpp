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
char s[110]="sunshine0.in";
int n,m,p;
int main()
{
	for (int i=6;i<10;i++)
	{
		s[8]=i+'0';
		freopen(s,"w",stdout);
		n=rand()%40000+10000;
		m=rand()%40000+100000;
		p=rand()%700000+300000;
		printf("%d %d %d\n",n,m,p);
		for (int j=1;j<=n;j++)
		{
			printf("%d",rand()%800+200);
			if (j!=n) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
