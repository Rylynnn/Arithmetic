/*
LANG:C++
ID:15829681
TASK:ariprog
*/
/*
wa1:递归堆栈溢出
wa2:数组越界
wa3:数组没开够
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LOCAL
#define N 130000
using namespace std;
int a[N],c[N],vis[N];
int n,m,number,pp;
struct node{
      int p;
      int q;

}d[N];
bool cmp2(node x,node e){
      return x.q<e.q;
      if(x.q==e.q){
            return x.p<e.q;
      }
}
int findall(){
      int i,j,k=0;
      for(i=0;i<=m;i++){
            for(j=i;j<=m;j++){
                  a[++k]=i*i+j*j;
                  c[i*i+j*j]=1;
            }
      }
      return k;
}
bool cmp1(int a,int b){
      return a<b;
}
int main()
{
      #ifdef LOCAL
      freopen("ariprog.in","r",stdin);
      freopen("ariprog.out","w",stdout);
      #endif // LOCAL
      int b,i,j,x;
      scanf("%d%d",&n,&m);
      memset(a,0,sizeof(a));
      memset(c,0,sizeof(c));
      memset(vis,-1,sizeof(vis));
      number=0;
      int num=findall();//找出所有组合
      sort(a+1,a+1+num,cmp1);
      for(i=1;i<=num;i++){
            for(j=i+1;j<=num;j++){
                  b=a[j]-a[i];
                  if((2-n)*a[i]+a[j]*(n-1)>m*m*2) break;
                  pp=0;
                  if(b!=0&&vis[b]!=a[i]){
                        for(x=2;x<=n;x++){
                              if(!c[a[i]+b*(x-1)]){
                                    pp=1;
                                    break;
                              }
                        }
                        if(!pp){
                              d[++number].p=a[i];
                              d[number].q=b;
                              //printf("%d%d\n",d[number].p,d[number].q);
                        }
                  }
                  vis[b]=a[i];
            }
      }
      if(number==0){
            printf("NONE\n");
      }
      else{
            sort(d+1,d+1+number,cmp2);
            for(i=1;i<=number;i++){
                  printf("%d %d\n",d[i].p,d[i].q);
            }
      }
      return 0;
}
