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
char s[10]="judge0.in";
char t[11]="judge0.out";
int n,k;
int a[310][310];
int main()
{
	srand(time(NULL));
	for (int T=5;T<7;T++)
	{
		s[5]=T+'0',t[5]=T+'0';
		freopen(s,"w",stdout);
		n=8,k=rand()%n+1;
		printf("%d %d\n",n,k);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i==j) printf("0");
				else if (i<j) printf("%d",a[i][j]=(rand()%300)*(rand()%3000)+100000);
				else printf("%d",a[j][i]);
				if (j==n) printf("\n");
				else printf(" ");
			}
		}
	}
	return 0;
}
