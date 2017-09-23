/*************************************************************************
    > File Name: b.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 二  9/19 23:47:33 2017
 ************************************************************************/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    vector<ll> son;
}tree[100007];
ll num1, num2;
ll dep[100007], vis[100007];
void dfs(ll x, ll d){
    dep[x] = d;
    if(d % 2 == 1){
        num1++;
    }
    else{
        num2++;
    }
    for(int i=0; i<tree[x].son.size(); ++i){
        if(!vis[tree[x].son[i]]){
            vis[tree[x].son[i]] = 1;
            dfs(tree[x].son[i], d+1);
        }
    }
    return;
}
int main()
{
    ll n, u, v;
    ll ans;
    cin >> n;
    num1 = num2 = 0;
    for(ll i=0; i<n-1; i++){
        cin >> u >> v;
        tree[u].son.push_back(v);
        tree[v].son.push_back(u);
    }
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    dfs(1, 1);
    ans = num1 * num2 - (n - 1);
    cout << ans << endl;
    return 0;
}
