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
char s[10];
int n,m;
int main()
{
	for (int i=4;i<=10;i++)
	{
		s[0]='d',s[1]='r',s[2]='u',s[3]='g',s[4]=i-1+'0',s[5]='.',s[6]='i',s[7]='n',s[8]='\0';
		freopen(s,"w",stdout);
		n=rand()%20000+180000,m=rand()%20000+180000;
		printf("%d %d\n",n,m);
		for (int j=1;j<=n;j++)
		{
			printf("%d",rand()%25+1);
			if (j!=n) printf(" ");
			else printf("\n");
		}
		for (int j=1;j<=m;j++)
		{
			printf("%d",rand()%100+1);
			if (j!=n) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
