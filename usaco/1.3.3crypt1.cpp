/*
LANG:C++
ID:15829681
TASK:crypt1
*/
/*
比起直接枚举给出的数的可能性，更好的是直接枚举111到999，和11到99直接检查五个数
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LOCAL
using namespace std;
int vis[10];
bool OK(int one){
      while(one){
            if(!vis[one%10]){
                  return false;
            }
            one/=10;
      }
      return true;
}
int main()
{
      #ifdef LOCAL
            freopen("crypt1.in","r",stdin);
            freopen("crypt1.out","w",stdout);
      #endif // LOCAL
      int n,i,j;
      int a[10],b,c,d,e,f,one,two,now,ans;
      scanf("%d",&n);
      memset(vis,0,sizeof(vis));
      for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]=1;
      }
      sort(a+1,a+1+n);
      int num=0;
      int p1,p2,p3 ;
      for(b=1;b<=n;b++){
            for(c=1;c<=n;c++){
                  for(d=1;d<=n;d++){
                        for(e=1;e<=n;e++){
                              for(f=1;f<=n;f++){
                                    if(a[b]!=0&&a[e]!=0){
                                          now=a[b]*100+a[c]*10+a[d];
                                          one=now*a[e];
                                          two=now*a[f];
                                          ans=one*10+two;
                                          if(one<=999&&two<=999&&ans<=9999&&OK(one)&&OK(two)&&OK(ans)){
                                                num++;
                                          }
                                    }
                              }
                        }
                  }
            }
      }
      printf("%d\n",num);
      return 0;
}
