/*
wa最后一个点原因竟然是因为我加了while 读入。。。。= =
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    long long b,e;
} poi[1009];
long long n;
long long a[1009],dp[1009][1009];
int main()
{
    scanf("%lld",&n);{
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        memset(poi,0,sizeof(poi));
        for(long long i=0; i<n; i++) {
            scanf("%lld",&a[i]);
        }
        for(long long i=0; i<n; i++) {
            poi[i].b=a[i];
            poi[i].e=a[(i+1)%n];
        }
        for(long long len=2; len<=n; len++) {
            for(long long i=0; i<n; i++) {
                long long j=(i+len-1)%n;
                for(long long k=i; k<i+len-1; k++) {
                    dp[i][j]=max(dp[i][j],dp[i][k%n]+dp[(k+1)%n][j]+poi[i].b*poi[k%n].e*poi[j].e);
                }
                //printf("%d %d %d\n",i,j,dp[i][j]);
            }
        }
        long long ans=0;
        for(long long i=0; i<n; i++) {
            long long j=(i+n-1)%n;
            ans=max(ans,dp[i][j]);
        }
        printf("%lld\n",ans);
    }
}
