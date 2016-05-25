#include<cstdio>
#include<cstring>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<ctime> 
#define MAXN 1000005

using namespace std;

const int MAXINF=1e9;
int tcnt;
struct Treap
{
	int root,key[MAXN],pri[MAXN],c[MAXN][2],cnt[MAXN],size[MAXN];
	void init()
	{
		root=0;
		pri[0]=MAXINF;
		size[0]=0;
	}
	void update(int x)
    {
		size[x]=size[c[x][0]]+cnt[x]+size[c[x][1]];
	}
	void rotate(int &x,int p)
	{
		int y=c[x][p];
		c[x][p]=c[y][1-p];
		c[y][1-p]=x;
		update(x);
		update(y);
		x=y;
	}
	void insert(int &x,int k)
	{
		if (x)
		{
			if (key[x]==k) cnt[x]++;
			else
			{
				int p=key[x]<k;
				insert(c[x][p],k);
				if (pri[c[x][p]]<pri[x]) rotate(x,p);
			}
		}
		else
		{
			x=++tcnt;
			key[x]=k;
			cnt[x]=1;
			pri[x]=rand();
			c[x][0]=c[x][1]=0;
		}
		update(x);
	}
	void erase(int &x,int k)
	{
		if (key[x]==k)
		{
			if (cnt[x]>1) cnt[x]--;
			else
			{
				if (c[x][0]==0&&c[x][1]==0)
				{
					x=0;
					return;
				}
				int p=pri[c[x][0]]>pri[c[x][1]];
				rotate(x,p);
				erase(x,k);
			}
		}
		else  erase(c[x][key[x]<k],k);
		update(x);
	}
	int getKth(int &x,int k)
	{
		if (k<=size[c[x][0]]) return getKth(c[x][0],k);
		k-=size[c[x][0]]+cnt[x];
		if (k<=0) return key[x];
		return getKth(c[x][1],k);
	}
}T;

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)==2)
	{
        tcnt=0;
		T.init();
	    for (int i=1;i<=n;i++)
	    {
		    char x;
		    int y;
		    scanf("%c",&x);
			while (x!='Q'&&x!='I')
			  scanf("%c",&x);
		    if (x=='I') scanf("%d",&y),T.insert(T.root,y);
		          else  printf("%d\n",T.getKth(T.root,T.size[T.root]-m+1));
		}
	}
	return 0;
} 
