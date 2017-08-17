/*************************************************************************
    > File Name: D.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月16日 星期三 18时46分57秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define MOD 1000000007
using namespace std;
bool cmp(ll a, ll b){
    return a < b;
}
ll pow_mod(ll a, ll b){
    ll mul = 1;
    a %= MOD;
    while(b){
        if(b % 2 == 1){
            mul = (mul * a) % MOD;
        }
        a = a * a % MOD;
        b = b >> 1; //cout << mul << endl;
    }
    return mul;
}
int main()
{
    ll n, k, ans = 0, a;
    scanf("%lld%lld", &n, &k);
    ll num2[100007], num[100007], vis[100007], tmp = 0;
    memset(num, 0, sizeof(num));
    for(ll i=0; i<n; i++){
        scanf("%lld", &a);
        if(a <= k){
            num2[++tmp] = a;
            num[tmp] = a;
        }
    }
    sort(num + 1, num + tmp + 1, cmp);
    ll l = 1, r = tmp;
    while(l <= r){
        if(num[l] + num[r] > k){
            r--;
        }
        else{
            ans += pow_mod(2, r - l);
            ans %= MOD;
            l++;
        }
    }
    printf("%lld", ans % MOD);
    return 0;
}
