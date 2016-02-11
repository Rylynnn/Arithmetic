#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
using namespace std;
int main()
{
    int k,i,j,n,maxm;
    int a[N],dp1[N],dp2[N];
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        dp1[1]=1;
        for(i=2;i<=n;i++){
            maxm=0;
            for(j=1;j<i;j++){
                if(a[i]>=a[j]){
                    maxm=max(maxm,dp1[j]);
                }
            }
            dp1[i]=maxm+1;
        }
        dp2[n]=1;
        for(i=n-1;i>=1;i--){
            maxm=0;
            for(j=n;j>i;j--){
                if(a[i]>=a[j]){
                    maxm=max(maxm,dp2[j]);
                    //printf("m:%d ",maxm);
                }
            }
            //printf("\n");
            dp2[i]=maxm+1;
            //printf("%d ",dp2[i]);
        }
        //printf("\n");
        int max1=-1;
        int max2=-1;
        for(i=1;i<=n;i++){
            max1=max(max1,dp1[i]);
            max2=max(max2,dp2[i]);
        }
        int ans;
        ans=max(max1,max2);
        printf("%d\n",ans);
    }
}
