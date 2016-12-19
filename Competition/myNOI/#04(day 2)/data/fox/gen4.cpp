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
int n,m,q;
int x,y,z;
struct node
{
	int x,y;
}a[51000];
int cmp(node a,node b)
{
	if (a.x!=b.x) return a.x<b.x;
	return rand()%2;
}
char s[]="fox0.in";
char t[]="fox0.out";
int main()
{
	for (int T=7;T<10;T++)
	{
		s[3]=T+'0',t[3]=T+'0';
		freopen(s,"w",stdout);
		n=rand()%20000+30000;
		q=rand()%20000+30000;
		m=(rand()%30000)+(rand()%20000);
		printf("%d %d %d\n",n,m,q);
		for (int i=1;i<=n;i++)
			a[i].x=(rand()%30000)+(rand()%20000),a[i].y=i;
		sort(a+1,a+1+n,cmp);
		for (int i=2;i<=n;i++)
			printf("%d %d %d\n",a[rand()%(i-1)+1].y,a[i].y,(rand()%30000)+(rand()%20000));
		for (int i=1;i<=q;i++)
		{
			int x=rand()%n+1,y=rand()%n+1;
			if (x>y) swap(x,y);
			printf("%d %d\n",x,y);
		}
	}
	return 0;
}
