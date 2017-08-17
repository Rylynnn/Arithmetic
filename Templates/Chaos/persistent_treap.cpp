#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define isdigit(x) (x>='0'&&x<='9')
#define SIZE(x) (x==NULL?0:x->size)
#define L(x) (x->rev^rf?x->r:x->l)
#define R(x) (x->rev^rf?x->l:x->r)
#define lim 2147483647
using namespace std;
struct node
{	int size;
	char v;
	node *l,*r;
	bool rev;
	node(char v):size(1),v(v),l(NULL),r(NULL),rev(false) {}
	node(node* p)
	{	*this=*p;
	}
	node() {}
	void pushdown();
};
inline bool operator <(const node& a,const node& b)
{	return (rand()|(rand()<<15))<(double)lim*(a.size/((double)a.size+b.size));
}
inline void update(node* a)
{	a->size=1;
	if (a->l)
		a->size+=a->l->size;
	if (a->r)
		a->size+=a->r->size;
}
char res[100005];
node* let[30];
node *root;
int rc;
inline void node::pushdown()
{	if (rev)
	{	if (l)
		{	l=new node(l);
			l->rev^=1;
		}
		if (r)
		{	r=new node(r);
			r->rev^=1;
		}
		swap(l,r);
		rev=false;
	}
}
node* merge(node* a,node* b)
{	if (a==NULL)
		return b;
	if (b==NULL)
		return a;
	if (*a<*b)
	{	a=new node(a);
		a->pushdown();
		a->r=merge(a->r,b);
		update(a);
		return a;
	}
	else 
	{	b=new node(b);
		b->pushdown();
		b->l=merge(a,b->l);
		update(b);
		return b;
	}
}
pair<node*,node*> split(node* a,int n)
{	if (a==NULL)
		return make_pair((node*)NULL,(node*)NULL);
	pair<node*,node*> p;
	a=new node(a);
	a->pushdown();
	if (SIZE(a->l)>=n)
	{	if (a->l==NULL)
			return make_pair((node*)NULL,a);
		p=split(a->l,n);
		a->l=p.second;
		update(a);
		return make_pair(p.first,a);
	}
	else 
	{	if (a->r==NULL)
			return make_pair(a,(node*)NULL);
		p=split(a->r,n-SIZE(a->l)-1);
		a->r=p.first;
		update(a);
		return make_pair(a,p.second);
	}
}
inline void insert(int x,char c)
{	if (root==NULL)
	{	root=new node(let[c-'a']);
		return ;
	}
	static pair<node*,node*> pr;
	pr=split(root,x);
	root=merge(merge(pr.first,let[c-'a']),pr.second);
}
inline void remove(int l,int r)
{	static pair<node*,node*> pr1,pr2;
	pr1=split(root,l-1);
	pr2=split(pr1.second,r-l+1);
	root=merge(pr1.first,pr2.second);
}
inline void duplicate(int l,int r,int x)
{	static pair<node*,node*> pr2;
	static node* pt;
	pt=split(split(root,l-1).second,r-l+1).first;
	pr2=split(root,x);
	root=merge(merge(pr2.first,pt),pr2.second);
}
inline void flip(int l,int r)
{	static pair<node*,node*> pr1,pr2;
	pr1=split(root,l-1);
	pr2=split(pr1.second,r-l+1);
	pr2.first->rev^=1;
	root=merge(pr1.first,pr2.first);
	root=merge(root,pr2.second);
}
char query(node* a,int x,bool rf)
{	if (SIZE(L(a))>=x)
		return query(L(a),x,rf^a->rev);
	else
	{	if (SIZE(L(a))+1==x)
			return a->v;
		else return query(R(a),x-SIZE(L(a))-1,rf^a->rev);
	}
}
inline void read(int &digit)
{	char c;
	digit=0;
	for (c=getchar();!isdigit(c);c=getchar());
	for (;isdigit(c);digit=digit*10+c-'0',c=getchar());
}
int main()
{	int i,q,l,r,x;
	char c,opr;
	freopen("editor.in","r",stdin);
	freopen("editor.out","w",stdout);
	scanf("%d\n",&q);
	for (i=0;i<26;++i)
		let[i]=new node('a'+i);
	while (q--)
	{	opr=getchar();
		switch (opr)
		{	case 'I':
			{	read(x);
				c=getchar();
				insert(x,c);
				break ;
			}
			case 'D':
			{	read(l),read(r);
				remove(l,r);
				break ;
			}
			case 'C':
			{	read(l),read(r),read(x);
				duplicate(l,r,x);
				break ;
			}
			case 'R':
			{	read(l),read(r);
				flip(l,r);
				break ;
			}
			case 'Q':
			{	read(x);
				res[++rc]=query(root,x,0);
				break ;
			}
		}
		scanf("\n");
	}
	res[++rc]='\0';
	puts(res+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//TEST20140321 editor
