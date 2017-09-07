/*************************************************************************
    > File Name: b.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  8/27 20:44:13 2017
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#define ll long long
#define MOD 1000000007
#define MAX 307
using namespace std;
ll kk[MAX], comb[MAX][MAX];
void init_kk(){
    kk[0] = 1;
    kk[1] = 1;
    for(ll i=2; i<MAX; i++){
        kk[i] = kk[i-1] * i % MOD;
    }
}
void init_comb(){
    comb[0][0] = 1;
    for(ll i=1; i<MAX; i++){
        comb[i][0] = 1ll;
        for(ll j=1; j<=i; j++){
            if(j == i){
                comb[i][j] = 1ll;
            }
            else{
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
            }
        }
    }
}
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    init_kk();
    init_comb();
    int n, k, x, y;
    ll ans;
    while(cin >> n >> k){
        for(int i=1; i<n; i++){
            cin >> x >> y;
        }
        ans = 0;
        for(ll i=1; i<=k; i++){
            ans += (((comb[n-1][i-1] * kk[i]) % MOD) * comb[k][i]) % MOD; 
            ans %= MOD;
        }
        cout << ans <<endl;
    }
    return 0;
}
