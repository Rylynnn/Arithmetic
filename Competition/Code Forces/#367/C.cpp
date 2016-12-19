#include <bits/stdc++.h>
#define eps 1e-6
#define INF 1e18
#define ll long long
using namespace std;
ll dp[100007][2],ans;
int n,a[100007],p[100007];
string b[100007],nowi,nowii;
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n){
        for(int i=0;i<n;i++){
            dp[i][0]=INF;
            dp[i][1]=INF;
        }
        memset(p,0,sizeof(p));
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        dp[0][0]=0;
        dp[0][1]=a[0];
        for(int i=1;i<n;i++){
            nowi=b[i],nowii=b[i-1];
            reverse(nowi.begin(),nowi.end());
            reverse(nowii.begin(),nowii.end());
            if(b[i]>=b[i-1]&&dp[i-1][0]!=INF){
                dp[i][0]=min(dp[i][0],dp[i-1][0]);
            }
            if(b[i]>=nowii&&dp[i-1][1]!=INF){
                dp[i][0]=min(dp[i][0],dp[i-1][1]);
            }
            if(nowi>=b[i-1]&&dp[i-1][0]!=INF){
                dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
            }
            if(nowi>=nowii&&dp[i-1][1]!=INF){
                dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
            }
        }
        //cout<<INF;
        ans=min(dp[n-1][0],dp[n-1][1]);
        if(ans!=INF){
            printf("%I64d\n",ans);
        }
        else{
            printf("-1\n");
        }
    }
}
