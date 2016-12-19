#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200010
bool cmp(int x,int y)
{
     return x>y;
}
int a[MAXN],b[MAXN],aa[MAXN],deep[MAXN],dao,n,m;
int main()
{
	freopen("drug.in","r",stdin);
	freopen("drug.out","w",stdout); 
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%d",&a[i]);
    rep(i,1,m)scanf("%d",&b[i]);
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);
    a[0]=1;
    int le=1,ri=m,ans=0;
    while(le<=ri)
    {
      int mid=le+ri>>1;
      bool pan=1;
      int nowb=mid,nowa=0;
      deep[0]=0;dao=0;
      rep(i,0,n)aa[i]=a[i];
      while(nowb)
      {
        while(b[nowb]==deep[nowa] && nowb && aa[nowa]){aa[nowa]--;nowb--;}
        int ha=min(dao+aa[nowa],n);
        rep(i,dao+1,ha)deep[i]=deep[nowa]+1;
        aa[nowa]-=ha-dao;
        while(aa[nowa] && deep[nowa]<=b[nowb] && nowb){aa[nowa]--;nowb--;}
        dao=ha;
        if(dao<nowa+1 || nowa==n)break;
        nowa++;
      }
      if(nowb)pan=0;
      if(pan){ans=mid;le=mid+1;}
      else ri=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
