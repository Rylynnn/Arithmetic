/*
dp[j]表示体积为j能不能被凑出来
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,v;
int a[37],dp[20009];
int main()
{
    while(scanf("%d%d",&v,&n)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=v;j>=a[i];j--){
                if(dp[j-a[i]]==1){
                    dp[j]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=v;i++){
            //printf("%d ",dp[i]);
            if(dp[i]==1)
                ans=i;
        }
        printf("%d\n",v-ans);
    }
}
