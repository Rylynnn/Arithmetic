#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int f[307][307],p1,p2,ans[307],aans[307];
int main()
{
    int n,a;
    while(scanf("%d",&n)!=EOF){
        memset(ans,INF,sizeof(ans));
        memset(aans,INF,sizeof(aans));
        memset(f,INF,sizeof(f));
        for(int i=1;i<=n+1;i++){
            for(int j=1;j<n+1;j++){
                scanf("%d",&a);
                f[i][a]=j;
            }
        }
        for(int j=1;j<=n;j++){
            if(j==1){
                p1=j;
                p2=0;
                for(int i=1;i<=n;i++){
                    if(p1!=i){
                        ans[i]=j;
                        aans[i]=f[i][p1];
                    }
                }
            }
            else{
                if(f[n+1][j]<f[n+1][p1]){
                    p2=p1;
                    p1=j;
                    for(int i=1;i<=n;i++){
                        if(f[i][p1]<aans[i]&&p1!=i){
                            ans[i]=j;
                            aans[i]=f[i][p1];
                        }
                        else if(f[i][p2]<aans[i]&&p1==i){
                            ans[i]=j;
                            aans[i]=f[i][p2];
                        }
                    }
                }
                else if(f[n+1][j]<f[n+1][p2]){
                    p2=j;
                    for(int i=1;i<=n;i++){
                        if(f[i][p2]<aans[i]&&p1==i){
                            ans[i]=j;
                            aans[i]=f[i][p2];
                        }
                    }
                }
            }
        }
        printf("%d",ans[1]);
        for(int i=2;i<=n;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
