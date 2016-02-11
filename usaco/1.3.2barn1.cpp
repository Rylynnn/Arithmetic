/*
ID: 15929681
LANG: C++
TASK: barn1
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 205
#define LOCAL
using namespace std;
bool cmp(int a,int b){
      return a>b;
}
bool cm(int a,int b){
      return a<b;
}
int main()
{
      #ifdef LOCAL
            freopen("barn1.in","r",stdin);
            freopen("barn1.out","w",stdout);
      #endif
      int m,s,c,i,b;
      int a[N],dis[N];
      scanf("%d%d%d",&m,&s,&c);
      b=0;
      for(i=1;i<=c;i++){
            scanf("%d",&a[i]);
      }
      if(m>=c){//如果木板数足够多，则每个牛棚一个木板就可以了。
            printf("%d\n",c);
            return 0;
      }
      sort(a+1,a+1+c,cm);
      for(i=1;i<c;i++){
            //printf("%d",a[i]);
            dis[i]=a[i+1]-a[i]-1;//先是每两个牛之间就放一个木板，然后从距离最大的木板开始拆，直到剩m个木板
            //cout<<dis[i]<<" ";
      }
      sort(dis+1,dis+c,cmp);
      b=fabs(a[1]-a[c])+1;
      for(i=1;i<=m-1;i++){
            b-=dis[i];
      }
      printf("%d\n",b);
      return 0;
}
