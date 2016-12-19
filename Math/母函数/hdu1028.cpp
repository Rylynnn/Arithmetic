#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#define inf 10000000000LL
#define MAX 100007
#define MOD 1000000007
#define ll long long
using namespace std;
int t,sum,now,ans;
ll dp[250007];
void p(){
    dp[1]=dp[0]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4;i<=150;i++){
        int flag=1;
        for(int j=1;;j++){
            int a=(j*j*3+j)/2;
            int b=(j*j*3-j)/2;
            if(a>i&&b>i){
                break;
            }
            if(a<=i){
                dp[i]+=dp[i-a]*flag;
            }
            if(b<=i){
                dp[i]+=dp[i-b]*flag;
            }
            flag*=-1;
        }
    }
}
int main()
{
    p();
    while(scanf("%d",&t)!=EOF){
        printf("%I64d\n",dp[t]);
    }
    return 0;
}

