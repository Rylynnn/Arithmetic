/*************************************************************************
    > File Name: hdu3336.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 二  9/12 22:37:26 2017
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const int N = 200007;
const int MOD = 10007;
typedef long long ll;
ll nxt[N];
ll dp[N];
string a;
void getnext(string str)
{    
    ll i,j;    
    ll slen = str.size();
    i=-1,j=0;
    nxt[0] = -1;
    while (j < slen){
        if (i == -1||str[i] == str[j]){    
            ++i,++j;
            nxt[j] = i;
            /*
            加速优化匹配的nxt数组，原nxt数组为前缀与后缀相同的最长子串长度，优化后为有可能可以重新匹配的下一个位置
            if (str[i] != str[j]){
                nxt[j] = i;
            }
            else {
                j = nxt[i];
            }
            */
        }
        else {
            i = nxt[i];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cin >> a;
        memset(nxt, 0, sizeof(nxt));
        getnext(a);
        /*for(int i=0; i<=n; i++){
            cout << nxt[i] << ' ';
        }*/
        memset(dp, 0, sizeof(dp));
        for(ll i=n; i>0; --i){
            dp[i] += 1;
            dp[i] %= MOD;
            dp[nxt[i]] += dp[i];
            dp[nxt[i]] %= MOD;
        }
        ll ans = 0;
        for(ll i=1; i<=n; ++i){
            //cout << dp[i] << ' ';
            ans += dp[i] % MOD;
            ans %= MOD;
        }
        cout << ans % MOD << endl;
    }
    return 0;
}
