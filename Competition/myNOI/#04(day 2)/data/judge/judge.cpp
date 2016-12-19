#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define M 301
#define inf 400000000
int n,k,a[M][M],f[M][M],ans[M],rem[20][M][M];
void work(int l,int r,int d)
{
     if(l==r)
     {
       ans[l]=inf;
       rep(i,1,n)
         rep(j,i+1,n)
           if(i!=l && j!=l)ans[l]=min(ans[l],f[i][j]+a[i][l]+a[l][j]);
       return ;
     }
     memcpy(rem[d],f,sizeof(f));
     int mid=l+r>>1;
     rep(k,mid+1,r)
       rep(i,1,n)
         rep(j,1,n)
           f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
     work(l,mid,d+1);
     memcpy(f,rem[d],sizeof(f));
     rep(k,l,mid)
       rep(i,1,n)
         rep(j,1,n)
           f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
     work(mid+1,r,d+1);

}
char s[10]="judge0.in";
char t[11]="judge0.out";
int main()
{
	rep(T,0,9)
	{
		s[5]=T+'0',t[5]=T+'0';
		freopen(s,"r",stdin);
		freopen(t,"w",stdout);
    	scanf("%d %d",&n,&k);
    	rep(i,1,n)
      		rep(j,1,n)
      		{
        		scanf("%d",&a[i][j]);
        		if(a[i][j]==-1)a[i][j]=inf;
      		}
   	 	memcpy(f,a,sizeof(a));
    	work(1,n,0);
    	sort(ans+1,ans+1+n);
    	rep(i,1,k)
    	{
			if (ans[i]==inf) break;
			printf("%d\n",ans[i]);
		}
	}
    return 0;
}
