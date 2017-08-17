/*************************************************************************
    > File Name: B.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年07月11日 星期二 22时11分00秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100009
using namespace std;
int n, a[N], tot, vis[N];
int dfs(int i){
    if(vis[i] != 0){
        return tot;
    }
    tot++;
    vis[i] = 1;
    int now = dfs(a[i]);
    vis[i] = now;
    return now;
}
int main()
{
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int maxm = 0;
    memset(vis, 0, sizeof(vis));
    for (int i=1;i<=n;i++){
        if(vis[i] == 0){
            tot = 0;
            maxm = max(maxm, dfs(a[i]));
        }
    }
    cout << maxm <<endl;
}
