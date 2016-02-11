/*
LANG:C++
ID:15829681
TASK:milk3
*/
#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#define IO
#define N 25
using namespace std;
int A,B,C;
int vis[N][N][N];
int ans[N];
void dfs(int a,int b,int c){
      if(vis[a][b][c]){
            return;
      }
      vis[a][b][c]=1;
      if(a==0){
            ans[c]=1;
            //printf("%d ",c);
      }
      if(a!=0&&b!=B){//a向b倒
            if(b+a>B){
                  dfs(a-(B-b),B,c);
            }
            else{
                  dfs(0,a+b,c);
            }
      }
      if(a!=0&&c!=C){//a向c倒
            if(c+a>C){
                  dfs(a-(C-c),b,C);
            }
            else{
                  dfs(0,b,a+c);
            }
      }
      if(b!=0&&a!=A){//b向a倒
            if(b+a>A){
                  dfs(A,b-(A-a),c);
            }
            else{
                  dfs(a+b,0,c);
            }
      }
      if(b!=0&&c!=C){//b向c倒
            if(b+c>C){
                  dfs(a,b-(C-c),C);
            }
            else{
                  dfs(a,0,b+c);
            }
      }
      if(c!=0&&a!=A){//c向a倒
            if(a+c>A){
                  dfs(A,b,c-(A-a));
            }
            else{
                  dfs(a+c,b,0);
            }
      }
      if(c!=0&&b!=B){//c向b倒
            if(b+c>B){
                  dfs(a,B,c-(B-b));
            }
            else{
                  dfs(a,b+c,0);
            }
      }
      return;
}
int main()
{
      #ifdef IO
      freopen("milk3.in","r",stdin);
      freopen("milk3.out","w",stdout);
      #endif // IO
      scanf("%d%d%d",&A,&B,&C);
      memset(vis,0,sizeof(vis));
      memset(ans,0,sizeof(ans));
      dfs(0,0,C);
      int p=0,i;
      for(i=0;i<N;i++){
            if(ans[i]==1){
                  if(p==0){
                        printf("%d",i);
                        p=1;
                  }
                  else{
                        printf(" %d",i);
                  }
            }
      }
      printf("\n");
      return 0;
}
