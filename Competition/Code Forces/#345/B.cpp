#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans,i;
    int a[1007];
    int num[1007];
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        memset(num,0,sizeof(num));
        ans=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ans=max(ans,++num[a[i]]);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
