/*
LANG:C++
ID:15829681
TASK:combo
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
//#define LOCAL
int N;
bool close(int a,int b){
      if(fabs(a-b)<=2){
            return true;
      }
      if(fabs(a-b)>=N-2){
            return true;
      }
      return false;
}
bool OK(int a,int b,int c,int x,int y,int z){
      if(close(a,x)&&close(b,y)&&close(c,z)){
            return true;
      }
      return false;
}
int main()
{
      #ifdef LOCAL
      freopen("combo.in","r",stdin);
      freopen("combo.out","w",stdout);
      #endif // LOCAL
      int a[4],b[4],i,j,k,pa1,pa2,pa3,pb1,pb2,pb3,num;
      scanf("%d",&N);
      scanf("%d%d%d",&a[1],&a[2],&a[3]);
      scanf("%d%d%d",&b[1],&b[2],&b[3]);
      num=0;
      for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                  for(k=1;k<=N;k++){
                        if(OK(a[1],a[2],a[3],i,j,k)||OK(b[1],b[2],b[3],i,j,k)){
                              num++;
                        }
                  }
            }
      }
      printf("%d\n",num);
      return 0;
}
