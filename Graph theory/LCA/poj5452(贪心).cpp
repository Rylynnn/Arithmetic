#include <cstdio>
#include <iostream>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define INF 0x3f3f3f3f
using namespace std;
int p[20007],pp[20007];
int main()
{
    int t,n,m,a,b;
    while(scanf("%d",&t)!=EOF){
        int kase=0;
        memset(p,0,sizeof(p));
        memset(pp,0,sizeof(pp));
        while(t--){
            kase++;
            scanf("%d%d",&n,&m);
            for(int i=0;i<n-1;i++){
                scanf("%d%d",&a,&b);
                p[a]++;
                p[b]++;
            }
            for(int i=n-1;i<m;i++){
                scanf("%d%d",&a,&b);
                pp[a]++;
                pp[b]++;
            }
            int ans=INF;
            for(int i=1;i<=n;i++){
                if(p[i]==1){
                    ans=min(ans,p[i]+pp[i]);
                }
            }
            printf("Case #%d: %d\n",kase,ans);
        }
    }
    return 0;
}
