/*
ID: 15829681
LANG: C++
TASK: milk
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#define LOCAL
#define N 5005
using namespace std;
struct node{
      int v;
      int nu;
}p[N];
bool cmp(node a,node b){
      return a.v<b.v;
}
int main()
{
      #ifdef LOCAL
            freopen("milk.in","r",stdin);
            freopen("milk.out","w",stdout);
      #endif
      int n,m,i,cost,num,now;
      int a[N];
      scanf("%d%d",&n,&m);
      for(i=1;i<=m;i++){
            scanf("%d%d",&p[i].v,&a[i]);
            p[i].nu=i;
      }
      sort(p+1,p+1+m,cmp);
      cost=0;
      num=0;
      i=0;
      int pp=0;
      while(++i<=m){
            if(num+a[p[i].nu]<=n){
                  num+=a[p[i].nu];
                  cost+=a[p[i].nu]*p[i].v;//a[p[i],num]竟然编译能过！！！！！！！！我中间是逗号！！！这种事情竟然编译能过？！
                  //printf("%d ",cost);
                  if(num==n){
                        printf("%d\n",cost);
                        pp=1;
                        break;
                  }
            }
            else{
                  now=n-num;
                  pp=1;
                  cost+=now*p[i].v;
                  printf("%d\n",cost);
                  break;
            }
      }
      if(!pp){
            printf("0\n");
      }
      return 0;
}
