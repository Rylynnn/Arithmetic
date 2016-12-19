#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    int t;
    while(scanf("%d",&t)!=EOF){
        int kase=0;
        while(kase++<t){
            scanf("%I64d",&n);
            printf("Case #%d: %I64d\n",kase,((n+1)*n)/2-1);
        }
    }
    return 0;
}
