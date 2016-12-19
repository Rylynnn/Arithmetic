/*
dp[i]表示以第i个数结尾的最长上升子序列长度
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int n,m;
int a[5007];
int dp[5007];
int main()
{
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            dp[i]++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<a[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
}
