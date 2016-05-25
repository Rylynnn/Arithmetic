#include <cstdio>
#include <cstring>
using namespace std;
int n,c,b,a[100007],vis[3],ans;
int main()
{
    int temp;
    while(scanf("%d%d%d",&n,&c,&b)!=EOF){
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            vis[a[i]]++;
        }
        int i=0,j=vis[0],k=vis[0]+vis[1];
        while(i<vis[0]) {
            if(a[i]==1) {
                while(j<vis[0]+vis[1]) {
                    if(a[j]==0) {
                        ans+=b;
                        int temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                        break;
                    }
                    ++j;
                }
            }
            else if(a[i]==2) {
                while(k<n) {
                    if(a[k]==0) {
                        ans+=b;
                        int temp=a[i];
                        a[i]=a[k];
                        a[k]=temp;
                        break;
                    }
                    ++k;
                }
            }
            ++i;
        }
        for(k=vis[0]+vis[1];k<n;++k) {
            if(a[k]==1) {
                ans+=b;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
