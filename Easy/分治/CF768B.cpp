/*************************************************************************
    > File Name: poj3714.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月02日 星期三 17时39分16秒
 ************************************************************************/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
ll lll, rrr;
ll n;
ll len;
ll dfs(ll l, ll r, ll now, ll nl, ll nr){
    if(nr < l || nl > r){
        return 0;
    }
    if(nr <= r && nl >= l){
        return now;
    }
    ll mid = (nl + nr) / 2;
    return dfs(l, r, now / 2, nl, mid- 1) + dfs(l, r, now % 2, mid, mid) + dfs(l, r, now / 2, mid+ 1, nr);
} 
int main()
{
    cin >> n >> lll >> rrr;
    ll now = n;
    len = 1;
    while(n > 1){
        n /= 2;
        len = 2 * len + 1;
    }
    cout << dfs(lll, rrr, now, 1, len) << endl;
}
