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
string a;
ll getnum(int i,int j){
    i--;
    j--;
    ll ans=a[i]-'0';
    for(int p=i+1;p<=j;p++){
        ans*=10;
        ans+=a[p]-'0';
    }
    return ans;
}
ll dp[59][11];
int main(){
    int n,k;
    ios_base::sync_with_stdio(false);
    while(cin>>n>>k){
        cin>>a;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            dp[i][0]=getnum(1,i);
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                for(int p=1;p<j;p++){
                    dp[j][i]=max(dp[p][i-1]*getnum(p+1,j),dp[j][i]);
                }
            }
        }
        printf("%lld\n",dp[n][k]);
    }
}
