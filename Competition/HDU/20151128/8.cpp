#include <bits/stdc++.h>
#define N 10007
using namespace std;
int main()
{
    int t;
    int n,m,k,i,ans;
    long long sum;
    int a[N],vis[N],p[N];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        memset(vis,0,sizeof(vis));
        sum=0;
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(i=1;i<=m;i++){
            scanf("%d",&p[i]);
            if(!vis[p[i]]){
                k-=a[p[i]];
                vis[p[i]]=1;
                a[p[i]]=0x3f3f3f3f;
            }
        }
        if(k<0){
            printf("-1\n");
        }
        else{
            sort(a+1,a+n+1);
            ans=m;
            for(i=1;i<=n;i++){
                k-=a[i];
                if(k>0){
                    ans++;
                }
                else{
                    break;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
