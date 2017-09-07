/*************************************************************************
    > File Name: poj3977.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 五  9/ 1 05:07:32 2017
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
#define INF 1e18
using namespace std;
pair<ll, ll> ans;
vector<pair<ll, ll> > sub1, sub2;
ll n, m, a[37], vis[37];
bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}
void dfs(ll num, ll ans, ll i, ll end, vector<pair<ll, ll> > &sub){
    if(i == end){
        if(num != 0){
            sub.push_back(pair<ll, ll>(ans, num));
        }
        return;
    }
    dfs(num+1, ans+a[i], i+1, end, sub);
    dfs(num, ans, i+1, end, sub);
}
void obs(ll a, ll b){
    if(b == 0){
        return;
    }
    if(a < 0){
        a = -a;
    }
    pair<ll, ll> p = pair<ll, ll>(a, b);
    if(p < ans){
        ans = p;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n){
        if(n == 0){
            break;
        }
        for(ll i=0; i<n; ++i){
            cin >> a[i];
        }
        sub1.clear(), sub2.clear();
        sort(a, a+n);
        m = n / 2;
        memset(vis, 0, sizeof(0));
        dfs(0, 0, 0, m, sub1);
        memset(vis, 0, sizeof(0));
        dfs(0, 0, m, n, sub2);
        sort(sub1.begin(), sub1.end(), cmp);
        sort(sub2.begin(), sub2.end(), cmp);
        ans.first = INF, ans.second = INF;
        for(ll i=0; i<sub2.size(); ++i){//wa1
            obs(sub2[i].first, sub2[i].second);
        }
        for(ll i=0; i<sub1.size(); ++i){
            obs(sub1[i].first, sub1[i].second);
        }
        /*for(int i=0; i<ans1.size(); i++){
            cout <<ans1[i].first << ' ' << ans1[i].second << endl;
        }
        for(int i=0; i<ans2.size(); i++){
            cout <<ans2[i].first << ' ' << ans2[i].second << endl;
        }*/
        for(ll i=0; i<sub1.size(); ++i){
            ll now = -sub1[i].first;
            vector<pair<ll, ll> >::iterator big = lower_bound(sub2.begin(), 
                                                              sub2.end(), 
                                                              pair<ll, ll>(now, 0ll));
            ll cnt1 = INF, cnt2 = INF;
            if(big != sub2.end()){//写成了两个if嵌套
                obs(big->first+sub1[i].first, big->second+sub1[i].second);
            }
            if(big != sub2.begin()){
                ·obs((big-1)->first+sub1[i].first, (big-1)->second+sub1[i].second);
            }
        }
        cout << ans.first << ' ' << ans.second << endl;
    }
    return 0;
}
