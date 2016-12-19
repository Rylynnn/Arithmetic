#include <bits/stdc++.h>
#define INF 0x7f7f7f7f7f7f7f7f
#define ll long long
using namespace std;
ll n,m,q;
ll c[107],p[107][107],dp[107][107][107];
int main()
{
    //cout<<0x3f3f3f3f;
    while(scanf("%I64d%I64d%I64d",&n,&m,&q)!=EOF){
        memset(dp,INF,sizeof(dp));
        for(ll i=1;i<=n;i++){
            scanf("%I64d",&c[i]);
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                scanf("%I64d",&p[i][j]);
            }
        }
        dp[0][0][0]=0;
        for(ll i=1;i<=n;i++){
            if(c[i]!=0){
                for(ll j=0;j<=m;j++){
                    for(ll k=0;k<=i;k++){
                        dp[i][c[i]][c[i]==j?k:k+1]=min(dp[i][c[i]][c[i]==j?k:k+1],dp[i-1][j][k]);
                    }
                }
            }
            else{
                for(ll j=1;j<=m;j++){
                    for(ll r=0;r<=m;r++){
                        for(ll k=0;k<=i;k++){
                            dp[i][j][j==r?k:k+1]=min(dp[i][j][j==r?k:k+1],dp[i-1][r][k]+p[i][j]);
                        }
                    }
                }
            }
        }
        ll ans=INF;
        for(ll j=1;j<=m;j++){
            ans=min(ans,dp[n][j][q]);
        }
        if(ans==INF){
            printf("-1\n");
        }
        else{
            printf("%I64d\n",ans);
        }
    }
}
