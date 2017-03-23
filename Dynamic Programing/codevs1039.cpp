
/*
dp[i][k]表示前i个数用k个乘号得到的最大的结果，三维dp
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
int f[7];
ll getnum(){
    f[0]=1;
    for(int i=1;i<=6;i++){
        f[i]=f[i-1]*i;
    }
}
ll dp[209][9];
int main(){
    int n,k;
    getnum();
    ios_base::sync_with_stdio(false);
    while(cin>>n>>k){
        k--;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                for(int p=1;p<j;p++){
                    dp[j][i]+=dp[p][i-1];
                }
            }
        }
        printf("%lld\n",dp[n][k]/f[k+1]);
    }
}
