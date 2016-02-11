#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int b1,b2,b3,b4,i,n;
    int dp[6000];
    memset(dp,0,sizeof(dp));
    dp[1]=1;
    b1=b2=b3=b4=1;
    for(i=2;i<=5843;i++){
        dp[i]=min(dp[b1]*2,min(dp[b2]*3,min(dp[b3]*5,dp[b4]*7)));//4个素因子各自算各自的（每次更新自己
        //printf("%d ",dp[i]);
        if(dp[b1]*2==dp[i]){
            b1++;
        }
        if(dp[b2]*3==dp[i]){
            b2++;
        }
        if(dp[b3]*5==dp[i]){
            b3++;
        }
        if(dp[b4]*7==dp[i]){
            b4++;
        }
    }
    while(scanf("%d",&n)!=EOF&&n){
        if(n%10==1&&n%100!=11){
            printf("The %dst humble number is %d.\n",n,dp[n]);
        }
        else if(n%10==2&&n%100!=12){
            printf("The %dnd humble number is %d.\n",n,dp[n]);
        }
        else if(n%10==3&&n%100!=13){
            printf("The %drd humble number is %d.\n",n,dp[n]);
        }
        else{
            printf("The %dth humble number is %d.\n",n,dp[n]);
        }
    }
    return 0;
}
