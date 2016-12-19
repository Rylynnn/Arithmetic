#include <bits/stdc++.h>
#define N 1000007
using namespace std;
void preKmp(int *src, int m, int *next){
  int i=0,j=-1;
  next[0]=j;
  while(i<m){
      while(j!=-1 && src[j] != src[i])
          j=next[j];
      i++,j++;
      if(j>=m)
          next[i]=next[j-1];
      else
          next[i]=j;
  }
}
int recount=0;
void kmp(int *src, int m, int *dest, int n,int p)
{
    int next[N];
    preKmp(src,m,next);
    int i=0, j=0;
    while(i<n){
        while(j!=-1 && src[j] != dest[i]){
            j = next[j];
        }
        i+=p,j++;
        if(j==m){
            recount++;
            j=next[j];
        }
    }
}
int a[N],b[N];
int main()
{
    int t,n,m,p;
    while(scanf("%d",&t)!=EOF){
        int kase=0;
        while(kase++<t){
            printf("Case #%d: ",kase);
            scanf("%d%d%d",&n,&m,&p);
            for(int i=0;i<n;i++){
                scanf("%d",&a[i]);
            }
            for(int i=0;i<m;i++){
                scanf("%d",&b[i]);
            }
            kmp(b,m,a,n,p);
            printf("%d\n",recount);
        }
    }
    return 0;
}
