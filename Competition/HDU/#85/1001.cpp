#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,a,t;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&n);
            int maxm=0;
            for(int i=0;i<n;i++){
                scanf("%d",&a);
                maxm=max(a,maxm);
            }
            printf("%d\n",maxm);
        }
    }
    return 0;
}
