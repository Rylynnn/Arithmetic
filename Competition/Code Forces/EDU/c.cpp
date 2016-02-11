#include <bits/stdc++.h>
using namespace std;
long long ans[300007][3];
int a[300007];
int main()
{
    int n,p,k,i,j;
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    p=0;
    k=0;
    ans[1][1]=1;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(j=ans[k][2]+1;j<i;j++){
            if(a[j]==a[i]){
                ++k;
                ans[k][2]=i;
                ans[k+1][1]=i+1;

            //printf("%d ",ans[i][1]);
            //printf("%d\n",ans[i][2]);

            }
        }
    }
    if(k==0){
        printf("-1");
    }
    else{
        ans[k][2]=n;
        printf("%d\n",k);
        for(i=1;i<=k;i++){
            printf("%d ",ans[i][1]);
            printf("%d\n",ans[i][2]);
        }
    }
    return 0;
}
