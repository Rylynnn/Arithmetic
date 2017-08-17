/*************************************************************************
    > File Name: A.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月01日 星期二 13时28分45秒
 ************************************************************************/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int ans = 0;
ll n;
void dfs(int i, ll now){
    if(now > n){
        return;
    }
    now *= 10;
    if(now <= n){
        ans++;
        dfs(i + 1, now);
    }
    if(now + 1 <=n){
        ans++;
        dfs(i + 1, now + 1);
    }
    return;
}
int main()
{
    while(scanf("%lld", &n)!=EOF){
        ans = 1;
        dfs(1, (ll)1);
        cout << ans << endl;
    }
    return 0;
}
