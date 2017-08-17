/*************************************************************************
    > File Name: CF626E.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月02日 星期三 21时44分49秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
ll n;
ll a[200007], s[200007];
ll cal(ll now, ll num){
    return s[n] - s[n-num] + s[now] - s[now-num-1];//最后这个数组越界了...
}
int main()
{
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    cin >> n;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    if(n == 1 || n == 2){
        cout << 1 <<endl;
        cout << a[1] <<endl;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        s[i] = s[i-1] + a[i];
    }
    ll L, R, count = 0;//count没有初始化...- -
    ll ans = 1, maxm = 0;   
    for(ll i=2; i<=n-1; i++){//算重了
        L = 0;
        R = min(i-1, n-i);
        while(L < R){
            ll xl = (2 * L + R) / 3;
            ll xr = (L + 2 * R + 2) / 3;
            ll yl = cal(i, xl);
            ll yr = cal(i, xr);
            if(yl * (2 * xr + 1) >= yr * (2 * xl + 1)){
                R = xr - 1;
            }
            else{
                L = xl + 1;
            }
        }
        ll mr = cal(i, L) - (2 * L + 1) * a[i];
        if(maxm * (2 * L + 1) < mr * (2 * count + 1)){
            maxm = mr;
            ans = i;
            count = L;
        }
        //cout << L << ' ' << ans <<endl;
    }
    cout << count * 2 + 1 << endl;
        for(ll i=ans-count; i<=ans; i++){
            cout << a[i] << ' ';
        }
        for(ll i=n-count+1; i<=n; i++){
            cout << a[i] << ' ';
        }
    return 0;
} 
