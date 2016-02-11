#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,d,ans;
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)!=EOF){
        ans=max(fabs(max(a,c)-min(a,c)),fabs(max(b,d)-min(b,d)));
        printf("%I64d\n",ans);
    }
    return 0;
}
