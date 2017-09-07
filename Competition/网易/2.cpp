/*************************************************************************
    > File Name: 2.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月13日 星期日 14时11分46秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
#define mod 1000000007
#define rep(i,n) for (int i=1;i<=(n);i++)
using namespace std;
ll pow_mod(ll a, ll b){
    ll ans = 1;
    a %= mod;
    while(b > 0){
        if(b & 1){
           ans = (ans*a) % mod;
        }
        b = b >> 1;
        a = (a*a) % mod;
    }
    return ans;
} 
ll J[1010],Jn[1010];
ll combine(ll n,ll m){
    return (((J[n]*Jn[m])%mod)*Jn[n-m])%mod;
}
int main()
{
    Jn[0]=J[0]=1;
    rep(i,1000) J[i]=(J[i-1]*i)%mod,Jn[i]=pow_mod(J[i],mod-2);

    ll _, n, m;
    scanf("%lld",&_);
    while (_--){
        scanf("%lld%lld",&n,&m);
        if (n>m) swap(n,m);
        printf("%lld\n",combine(m,n));
    }
    return 0;
}
