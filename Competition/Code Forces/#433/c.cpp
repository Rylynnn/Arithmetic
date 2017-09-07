/*************************************************************************
    > File Name: c.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 三  9/ 6 21:29:07 2017
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
using namespace std;
ll a[300007];
ll n, k, res, ans[300007], sum;
struct cmp{
    bool operator ()(ll m, ll q){
        return a[q] > a[m];
    }
};
priority_queue<ll, vector<ll>, cmp> h;
void cal(){
    ll tmp = 1, pp = k+1;
    while(!h.empty()){
        ll now = h.top();
        ans[now] = tmp + k;
        tmp++;
        h.pop();
        pp++;
        if(pp <= n){
            h.push(pp);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(ll i=1; i<=n; i++){
        cin >> a[i];
        sum += i * a[i];
    }
    for(ll i=1; i<=k+1; i++){
        h.push(i);
    }
    cal(); 
    ll res = 0;
    for(ll i=1; i<=n; i++){
        res += ans[i] * a[i];
    }
    res -= sum;
    cout << res << endl;   
    cout << ans[1];
    for(ll i=2; i<=n; i++){
        cout << ' ' << ans[i];
    }
    return 0;
}

