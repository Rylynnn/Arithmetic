#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,a,b;
    while(scanf("%I64d",&n)!=EOF){
        int kase=0;
        while(kase++<n){
            scanf("%I64d%I64d",&a,&b);
            if(a==b){
                printf("Case #%d:\n",kase);
                printf("1\n");
                printf("%I64d %I64d\n",a,b);
            }
            else{
                printf("Case #%d:\n",kase);
                printf("2\n");
                printf("%I64d %I64d\n",a,b);
                printf("%I64d %I64d\n",b,a);
            }
        }
    }
    return 0;
}
