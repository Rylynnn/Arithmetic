#include <stdio.h>
int main()
{
    int n,a;
    long long ans;
    while(scanf("%d",&n)!=EOF){
        ans=1;
        while(n--){
            scanf("%d",&a);
            if(a&1){
                ans*=a;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
