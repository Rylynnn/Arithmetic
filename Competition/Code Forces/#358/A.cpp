#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,nn,mm,ni[5],mi[5];
    long long ans;
    while(scanf("%d%d",&n,&m)!=EOF){
        ans=0;
        for(int i=1;i<=n;i++){
            ans+=(m+i%5)/5;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
