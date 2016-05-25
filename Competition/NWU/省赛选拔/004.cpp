#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#define MAXN 100001
#define fab(a) (a)>0?(a):(-a)
#define INF 0xfffffff
#define LL long long
using namespace std;
int a[MAXN];
int dp[MAXN];
int main()
{
    int n,s,M,i,j;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        s=0;
        memset(dp,0,sizeof(dp));
        for(i=0; i<n; i++){
            scanf("%d",&a[i]);
            s+=a[i];
        }
        M=s/2;
        for(i=0; i<n; i++) {
            for(j=M; j>=a[i]; j--) {
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
        }
        printf("%d\n",s-(2*dp[M]));
    }
    return 0;
}
