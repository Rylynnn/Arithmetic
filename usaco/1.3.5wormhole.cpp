/*
LANG:C++
ID:15829681
TASK:wormhole
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 15
#define LOCAL
using namespace std;
struct node{
      int x;
      int y;
      int next;
      int pa;
}a[N];
int vis[N],p[N];
int ans;
int n;
bool cmp(node b,node c){
      return b.x<c.x;
}
bool haveloop(int i){
      if(a[a[i].pa].next==a[i].pa){//当前点的对洞口的下一个不存在
            return false;
      }
      if(vis[i]){
            return true;
      }
      vis[i]=1;
      return haveloop(a[a[i].pa].next);
}
void getpair(int now){//局部变量和全局变量重名！！！！！！
      int i,j;
      //cout<<n;
      if(!now){
            for(i=1;i<=n;i++){
                        //cout<<i;
                  memset(vis,0,sizeof(vis));
                  if(haveloop(i)){
                        ans++;
                       //printf("%d ",ans);
                        break;
                  }
            }
            return;
      }
      for(i=1;i<=n;i++){
            if(!p[i]){
                  p[i]=1;
                  break;
            }
      }
      for(j=i+1;j<=n;j++){
            if(!p[j]){
                  p[j]=1;
                  a[i].pa=j;
                  a[j].pa=i;
                  getpair(now-1);
                  p[j]=0;
            }
      }
      p[i]=0;
}
int main()
{
      #ifdef LOCAL
      freopen("wormhole.in","r",stdin);
      freopen("wormhole.out","w",stdout);
      #endif // LOCAL
      int i,j;
      scanf("%d",&n);
      for(i=1;i<=n;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
      }
      sort(a+1,a+1+n,cmp);
      for(i=1;i<=n;i++){
            a[i].next=i;
            a[i].pa=i;
            //printf("%d%d\n",a[i].x,a[i].y);
      }
      memset(p,0,sizeof(p));
      ans=0;
      for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                  if(a[j].y==a[i].y){
                        a[i].next=j;//下一个会走到的点的下标
                        break;
                  }
            }
      }
      getpair(n>>1);
      printf("%d\n",ans);
      return 0;
}
