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
	int data,num,size,c[2],fa;
}tree[maxn];
int root=0,sum=0,res;
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
void splay(int x)
{
	while (tree[x].fa!=0)
	{
		int y=tree[x].fa;
		int z=tree[y].fa;
		if (z==0)
		{
			if (tree[y].c[0]==x) rotate(x,1);
			                 else rotate(x,0);
			break;
		}
		int a=y==tree[z].c[0]?1:0;
		int b=x==tree[y].c[0]?1:0;
		if (a^b)  rotate(x,b),rotate(x,a);
		    else  rotate(y,a),rotate(x,b);
	}
	root=x;
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
		if (x==tree[y].data)
		{
			pos=y;
			tree[y].num++;
			maintain(y);
			break;
		}
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
	splay(pos);
}
int findpos(int x,int z)
{
    int p,y=root,d=0;
    while (x!=tree[y].data)
    {
		p=0;
		if (x>tree[y].data) p=1;
		if (p&&z) d+=tree[tree[y].c[0]].size+tree[y].num;
		y=tree[y].c[p];
	}
	if (z) return d+tree[tree[y].c[0]].size+1;
	  else return y;  
}
int find(int x,int p)
{
	x=findpos(x,0);
	splay(x);
	int y=root;
	y=tree[y].c[p];
	while (tree[y].c[p^1])
	  y=tree[y].c[p^1];
	return y;
}
void del(int x)
{
    int pos=findpos(x,0);
	splay(pos);
	if (tree[pos].num>1)
	{
	    tree[pos].num--;
	    tree[pos].size--;
    }
	else
	{
		if (tree[pos].c[0]!=0)
		{
		    tree[tree[pos].c[0]].fa=0;
            int f=find(tree[pos].data,0);
            tree[tree[pos].c[1]].fa=f;
            tree[f].c[1]=tree[pos].c[1];
            maintain(tree[pos].c[1]);
            root=tree[pos].c[0];
            tree[pos].c[0]=0;
            tree[pos].c[1]=0;
		}
		else
		{
			tree[tree[pos].c[1]].fa=0;
			root=tree[pos].c[1];
		}
	}
}
int finddata(int x)
{
	int y=root;
	while (x<=tree[tree[y].c[0]].size||x>tree[tree[y].c[0]].size+tree[y].num)
	{
		if (x<=tree[tree[y].c[0]].size) y=tree[y].c[0];
		else  
		{
			x-=tree[tree[y].c[0]].size+tree[y].num;
			y=tree[y].c[1];
		}
	}
	return tree[y].data;
} 
int main()
{
	int n,op,y;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&op,&y);
		switch(op)
		{
			case 1:insert(y,++sum);break;
			case 2:del(y);break;
		    case 3:printf("%d\n",findpos(y,1));break;
		    case 4:printf("%d\n",finddata(y));break;
		    case 5:insert(y,++sum);printf("%d\n",tree[find(y,0)].data);del(y);break;
		    case 6:insert(y,++sum);printf("%d\n",tree[find(y,1)].data);del(y);break;
		}	
	}
	return 0;
}
