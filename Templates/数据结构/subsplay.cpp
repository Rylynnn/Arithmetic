#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

const int maxn=110000;
struct node
{
	int data,num,size,c[2],fa,rev;
}tree[maxn];
int root=0,sum=0,res,n,m,num=0;
void downdate(int x)
{
	if (!tree[x].rev) return;
	tree[x].rev=0;
	tree[tree[x].c[0]].rev^=1;
	tree[tree[x].c[1]].rev^=1;
	swap(tree[x].c[0],tree[x].c[1]);
}
void update(int x)
{
	tree[x].size=tree[tree[x].c[0]].size+tree[tree[x].c[1]].size+tree[x].num;
}
void rotate(int x,int p)
{
	int y=tree[x].fa;
	if (tree[x].c[p]) tree[tree[x].c[p]].fa=y;
    tree[y].c[p^1]=tree[x].c[p];
    tree[x].c[p]=y;
    tree[x].fa=tree[y].fa;
    tree[y].fa=x;
    if (tree[x].fa)  if (y==tree[tree[x].fa].c[0]) tree[tree[x].fa].c[0]=x;
                                             else  tree[tree[x].fa].c[1]=x;
    update(y); 
    update(x);
}
void splay(int x,int p)
{
	while (tree[x].fa!=0)
	{
		int y=tree[x].fa;
		int z=tree[y].fa;
		downdate(z);
	    downdate(y);
	    downdate(x);
		if (z==0||(tree[z].fa==0&&p))
		{
			if (p&&z==0) break;
			if (tree[y].c[0]==x) rotate(x,1);
			                 else rotate(x,0);
			break;
		}
		int a=y==tree[z].c[0]?1:0;
		int b=x==tree[y].c[0]?1:0;
		if (a^b)  rotate(x,b),rotate(x,a);
		    else  rotate(y,a),rotate(x,b);
	}
	if (!p) root=x;
}
void maintain(int x)
{
	while (x!=0)
		update(x),x=tree[x].fa;
}
void init(int x,int sum)
{
     tree[sum].data=x;
     tree[sum].fa=0;
     tree[sum].c[0]=0;
     tree[sum].c[1]=0;
     tree[sum].num=1;
     tree[sum].size=1;
     tree[sum].rev=0;
}
void insert(int x,int sum)
{
	int y=root;
	int pos=0;
	init(x,sum);
	if (y==0)
	{
		 root=sum;
		 return;
	}
	while (true)
	{
		tree[y].size++;
		int p=1;
		if (x<tree[y].data) p=0;
		if (tree[y].c[p]==0)
		{
			tree[y].c[p]=sum;
			tree[sum].fa=y;
			break;
		}
		else y=tree[y].c[p];
	}
	if (pos==0) pos=sum;
	splay(pos,0);
}
int findpos(int x)
{
	int y=root;
	downdate(y);
	while (x<=tree[tree[y].c[0]].size||x>tree[tree[y].c[0]].size+tree[y].num)
	{
		if (x<=tree[tree[y].c[0]].size) y=tree[y].c[0];
		else  
		{
			x-=tree[tree[y].c[0]].size+tree[y].num;
			y=tree[y].c[1];
		}
		downdate(y);
	}
	return y;
} 
int find(int x,int p)
{
	x=findpos(x);
	splay(x,0);
	int y=root;
	downdate(y);
	y=tree[y].c[p];
	while (tree[y].c[p^1])
	  y=tree[y].c[p^1],downdate(y);
	return y;
}
void print(int x)
{
	downdate(x);
	if (tree[x].c[0]) print(tree[x].c[0]);
	if (x!=1&&x!=n+2)
	{  
		num++;
		printf("%d",tree[x].data);
		if (num!=n) printf(" ");
	}
	if (tree[x].c[1]) print(tree[x].c[1]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n+2;i++)
	  insert(i-1,++sum);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int fx=find(x+1,0),fy=find(y+1,1);
		splay(fx,0);
		splay(fy,1);
		tree[tree[fy].c[0]].rev^=1;
	}
	print(root);	
	return 0;
}
