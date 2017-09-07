/*************************************************************************
    > File Name: 1002.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月17日 星期四 13时30分44秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define N 1000007
#define MOD 1000000007
using namespace std;
int mu[N], g[N], num[N], prime[N], vis[N], ans[N];
void init()
{
    for(int i=0; i<N; ++i){
        ans[i] = 0, g[i] = 1, num[i] = 0, vis[i] = 0, prime[i] = 0, mu[i] = 0;
    }
    num[1] = 1;
    mu[1] = 1;
    int tot = 0;
    for(int i=2; i<N; ++i){
        if(!vis[i]){
            vis[i] = 1;
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j=0; j<tot && i*prime[j]<N; ++j){
            vis[i*prime[j]] = 1;
            if(i%prime[j]){
                mu[i*prime[j]] = -mu[i];
            }
            else{
                mu[i*prime[j]] = 0;
                break;
            }
        }
        for(int j=i; j<N; j+=i){//之前是nsqrt(n)的复杂度
            g[j] += 1;
        }
    }
    for(int i=2; i<N; ++i){
        num[i] = num[i-1] + g[i-1] + 1;
    }
    for(int i=1; i<N; ++i){
        for(int j=i; j<N; j+=i){
            ans[j] = ((mu[i] * num[j/i] % MOD) + ans[j]) % MOD;
        }
    }
    for(int i=1; i<N; ++i){
        ans[i] = (ans[i] + ans[i-1]) % MOD;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    init();
    while(cin >> n){
        cout << ans[n] << endl;
    }
    return 0;
}
