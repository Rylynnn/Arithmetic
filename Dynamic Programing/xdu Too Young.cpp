#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000010
using namespace std;
int s[N];
int dp[N];
int main()
{
    int a,b,t,sum,i;
    memset(dp,0,sizeof(dp));
    memset(s,0,sizeof(s));
    dp[1]=0;
    s[1]=0;
    for(i=2;i<=N;i++){
        if(i&1){
            dp[i]=dp[i-1]+1;
            s[i]=s[i-1]+dp[i];
        }
        else{
            dp[i]=min(dp[i-1],dp[i/2])+1;
            s[i]=s[i-1]+dp[i];
        }
        //printf("%d %d %d\n",i,dp[i],s[i]);
    }
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a>b){
            a=t,a=b,b=t;
        }
        sum=0;
        sum=s[b]-s[a]+dp[a];
        printf("%d\n",sum);
    }
}
