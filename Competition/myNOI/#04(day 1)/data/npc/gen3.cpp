#pragma comment(linker, "/STACK:102400000,102400000")
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
char s[110]="npc0.in";
struct node
{
	int x,y;
}a[1100000];
int cmp(node a,node b)
{
	return a.y<b.y;
}
int n;
int main()
{
	srand(time(NULL));
	for (int T=5;T<10;T++)
	{
		s[3]=T+'0';
		freopen(s,"w",stdout);
		n=rand()%900000+100000;	
		printf("%d\n",n);
		for (int j=1;j<=n;j++)
			printf("%d%c",rand()%8000+2000,j==n?'\n':' ');
		for (int i=1;i<=n;i++)
			a[i].x=i,a[i].y=rand()%1100000;
		sort(a+1,a+1+n,cmp);
		for (int i=1;i<n;i++)
			printf("%d %d %d\n",a[rand()%i+1].x,a[i+1].x,rand()%8000+2000);
	}
	return 0;
}
