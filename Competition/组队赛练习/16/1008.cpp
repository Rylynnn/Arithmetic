#include <bits/stdc++.h>
#define N 1000007
using namespace std;
void preKmp(int *src, int m, int *rule){
  int i=0,j=-1;
  rule[0]=j;
  while(i<m){
      while(j!=-1 && src[j] != src[i])
          j=rule[j];
      i++,j++;
      if(j>=m)
          rule[i]=rule[j-1];
      else
          rule[i]=j;
  }
}
int recount=0;
void kmp(int *src, int m, int *dest, int n,int p)
{
    int rule[N];
    preKmp(src,m,rule);
    int i=0, j=0;
    for(int k=0;k<p;k++)
        for(j=0,i=k;i<n;){
            while(j!=-1 && src[j] != dest[i]){
                j = rule[j];
            }
            i+=p,j++;
            if(j==m){
                recount++;
                j=rule[j];
            }
    }
}
int Reg[N],ori[N];
int main()
{
    int t,n,m,p;
    scanf("%d",&t);
    int kase=0;
    while (kase++<t){
        recount=0;
        scanf("%d%d%d",&n,&m,&p);
        for(int i=0;i<n;i++){
            scanf("%d",&ori[i]);
        }
        for(int i=0;i<m;i++){
            scanf("%d",&Reg[i]);
        }
        kmp(Reg,m,ori,n,p);
        printf("Case #%d: ",kase);
        printf("%d\n",recount);
    }
    return 0;
}
