
#include <cstdio>
int main()
{
    int t,sum,n,a;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            sum=0;
            scanf("%d",&n);
            sum+=n;
            for(int i=1;i<=n;i++){
                scanf("%d",&a);
                sum+=a;
            }
            printf("%d\n",sum);
        }
    }
    return 0;
}
