/*
求最长下降和最长上升子序列
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int n,m;
int a[29];
int dp[5007];
int main()
{
    int tot=0;
    while(scanf("%d",&a[tot++])!=EOF){
    }
    tot--;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<tot;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]>a[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=0;i<tot;i++){
        //printf("%d ",dp[i]);
        if(ans<dp[i]){
            ans=dp[i];
        }
    }
    printf("%d\n",ans);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<tot;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    ans=0;
    for(int i=0;i<tot;i++){
        if(ans<dp[i]){
            ans=dp[i];
        }
    }
    printf("%d\n",ans);
}
