#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100010
struct ques
{
       int l,r,n;
}qu[MAXN];
struct tnode
{
       int sum,l,r,z;
}t[2*MAXN];
int n,m,qs,l[MAXN],ln[MAXN],ls,beg[MAXN],lc[MAXN],f[MAXN],unit,ans,ts,re[MAXN];
bool cmp(ques a,ques b)
{	
    return a.l/unit<b.l/unit||(a.l/unit==b.l/unit&&a.r<b.r);
}
void dfs(int u,int last)
{
     for(int now=beg[u];now;now=ln[now])
     if(l[now]!=last)
     {
       f[l[now]]=f[u]^lc[now];
       dfs(l[now],u);
     }
}
void addedge(int u,int v,int c)
{
     l[++ls]=v;ln[ls]=beg[u];beg[u]=ls;lc[ls]=c;
     l[++ls]=u;ln[ls]=beg[v];beg[v]=ls;lc[ls]=c;
}
void work(int u,int z,int now,int e)
{
     if(u==0)return ;
     if(now>m){ans+=t[u].sum*e;return;}
     if(now+t[u].z*2<=m)return;
     if(z&t[u].z)//1
     {
       work(t[u].l,z,now+t[u].z,e);
       work(t[u].r,z,now,e);
     }
     else
     {
       work(t[u].r,z,now+t[u].z,e);
       work(t[u].l,z,now,e);
     }
}
void addnode(int u,int z,int e)
{
     t[u].sum+=e;
     if(t[u].z==0)return;
     if((t[u].z&z)==0)
     {
       if(t[u].l==0)
       {
         t[u].l=++ts;
         t[ts].z=t[u].z>>1;
         t[ts].l=t[ts].r=t[ts].sum=0;
       }
       addnode(t[u].l,z,e);
     }
     else
     {
       if(t[u].r==0)
       {
         t[u].r=++ts;
         t[ts].l=t[ts].r=t[ts].sum=0;
         t[ts].z=t[u].z>>1;
       }
       addnode(t[u].r,z,e);
     }
}
void add(int z)
{
     work(1,z,0,1);
     addnode(1,z,1);
}
void del(int z)
{
     addnode(1,z,-1);
     work(1,z,0,-1);
}
char s[]="fox0.in";
char tt[]="fox0.out";
int main()
{
    for (int T=0;T<10;T++)
    {
		s[3]=T+'0',tt[3]=T+'0';
		freopen(s,"r",stdin);
		freopen(tt,"w",stdout);
		scanf("%d%d%d",&n,&m,&qs);
      	memset(beg,0,sizeof(beg));
      	ls=ans=ts=0;
    	rep(i,1,n-1)
    	{
      		int u,v,c;
      		scanf("%d%d%d",&u,&v,&c);
      	addedge(u,v,c);
    	}
    	dfs(1,0);
    	unit=int(sqrt(double(n)))+1;
    	rep(i,1,qs){scanf("%d%d",&qu[i].l,&qu[i].r);qu[i].n=i;}
    	sort(qu+1,qu+1+qs,cmp);
    	int le=qu[1].l,ri=qu[1].l-1;
    	ts++;t[1].z=1<<17;t[1].sum=t[1].l=t[1].r=0;
    	rep(i,1,qs)
    	{
      		while(le>qu[i].l)
      		{
        		le--;add(f[le]);
      		}
      		while(le<qu[i].l)
      		{
        		del(f[le]);le++;
      		}
      		while(ri>qu[i].r)
      		{
        		del(f[ri]);ri--;
      		}
      		while(ri<qu[i].r)
      		{
        		ri++;add(f[ri]);
      		}
      		re[qu[i].n]=ans;
    	}
    	rep(i,1,qs)
			printf("%d\n",re[i]);
    }
    return 0;
}
