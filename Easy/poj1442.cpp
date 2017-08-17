/*************************************************************************
    > File Name: C.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年07月31日 星期一 22时48分45秒
 ************************************************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
ll power_mod(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = ((ans % 1000) * (a % 1000)) % 1000;
        }
        a = (a % 1000) * (a % 1000) % 1000;
        b = b >> 1;
    }
    return ans;
}
int main()
{
    ll t, n, k, ans2;
    double ans1;
    scanf("%lld", &t);
    ll num = 0;
    while(t--)
    {
        num++;
        cin >> n >> k;
        ans2 = power_mod(n, k) % 1000;
        ans1 = (double)k * log10((double) n);
        ans1 = ans1 - (ll)ans1;
        cout << "Case " << num << ": " << (ll)(pow(10, ans1) * 100) << ' ';
        printf("%03lld\n", ans2);//可以的03lld可以自动填充 
    }
    return 0;
}
