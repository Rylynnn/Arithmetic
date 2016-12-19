#include <cmath>
#include <cstdio>
#include <cstring>
#define MAX 100007
using namespace std;
int main()
{
    int a,b,n,ans;
    while (scanf("%d",&n)!=EOF){
        while(scanf("%d",&a)!=EOF){
            if(a==0){
                break;
            }
            scanf("%d",&b);
            int vis[MAX];
            memset(vis,0,sizeof(vis));
            int i=1,sum=1;
            ans=0;
            while(i){
                sum=sum*a%n;
                if(vis[sum]==1){
                    break;
                }
                vis[sum]=1;
                if(sum==b){
                    ans=i;
                    break;
                }
                i++;
            }
            printf("%d\n",ans);
        }
    }
}
