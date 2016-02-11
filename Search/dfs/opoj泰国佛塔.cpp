#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int R,H,n,m,ans,mv[21],tmp;
void dfs(int v,int dep,int R,int H) {
     if (dep==0) {
                 if (v==0 && tmp<ans) ans=tmp;
                 return;
     }
     if (v-mv[dep-1]<0 || tmp>=ans || 2*v/R+tmp>=ans) return;
     for (int r=R-1;r>=dep;r--) {
         int Hm = min(H-1,(v-mv[dep-1])/r/r);
         for (int h=Hm;h>=dep;h--)
             if ((v-r*r*h)>=0) {
                if (dep==m) tmp=r*r;
                tmp+=2*r*h;
                dfs(v-r*r*h,dep-1,r,h);
                tmp-=2*r*h;
                if (dep==m) tmp=0;
             }
     }
}
int main() {
    memset(mv,0,sizeof(mv));
    for (int i=1;i<=m;i++)
        mv[i]=mv[i-1]+i*i*i;
    while (~scanf("%d%d",&n,&m)) {
          ans=10000000;
          dfs(n,m,n+1,n+1);
          if (ans==10000000) printf("0\n");
          else printf("%d\n",ans);
    }
    return 0;
}
