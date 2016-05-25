#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    int ans[2009],a[2009];
    scanf("%d",&n);
    memset(ans,0,sizeof(ans));
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ans[a[i]]++;
    }
    for(i=1;i<=2007;i++){
        ans[i]=1;
        for(j=i+1;j<=2007;j++){
            ans[i]+=ans[j];
        }
    }
    for(i=1;i<n;i++){
        printf("%d ",ans[a[i]]);
    }
    printf("%d\n",ans[a[n]]);
    return 0;
}
