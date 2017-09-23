/*************************************************************************
    > File Name: luogup1600.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 三  9/13 20:30:23 2017
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
struct node{
    vector<int> son;
    int fa;
}tree[300007];
int n, m, T;
int tmp[6300007], dep[300007], st[300007][32];
int w[300007], num[300007];
void dfs(int x, int p){
    tmp[++T] = x;
    dep[x] = p;
    for(int i=0; i<tree[x].son.size(); ++i){
        tree[tree[x].son[i]].fa = x;
        dfs(tree[x].son[i], p+1);
        tmp[++T] = x;
    }
    return;
}
void get_st(){
    for(int i=1; i<=T; ++i){
        st[i][0] = tmp[i];
    }
    for(int j=1; (j<<1)<=T; ++j){
        for(int i=1; i<=T; ++i){
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
}
int find_lca(int x, int y){
    if(x > y){
        swap(x, y);
    }
    int j = 0;
    while((1 << j) <= (y - x + 1)){
        j++;
    }
    j--;
    return min(st[x][j], st[y - (1 << j)+1][j]);
}
int main()
{
    int u, v;
    cin >> n >> m;
    for(int i=0; i<n-1; ++i){
        cin >> u >> v;
        if(u > v) swap(u, v);
        tree[u].son.push_back(v);
    }
    for(int i=0; i<n; ++i){
        cin >> w[i+1];
    }
    T = 0;
    int ans = 0, fa;
    dfs(1, 1);
    /*for(int i=1; i<=T; ++i){
        cout << tmp[i] << ' ';
    }*/
    get_st();
    for(int i=0; i<m; ++i){
        cin >> u >> v;
        fa = find_lca(u, v);
        ans = dep[u] - 2 * dep[fa] + dep[v];
        cout << ans;
        if(ans == w[v]){
            num[v]++;
        }
    }
    cout << num[1];
    for(int i=2; i<=n; ++i){
        cout << ' ' << num[i];
    }
    return 0;
}
