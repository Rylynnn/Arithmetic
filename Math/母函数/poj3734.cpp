#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#define inf 10000000000LL
#define MAX 1000007
#define MOD 10007
#define ll long long
using namespace std;
int a[MAX],b[MAX];
ll power_mod(ll a,ll b){
    ll ret=1;
    while(b){
        if(b&1){
            ret=(ret*a)%MOD;
        }
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int main()
{
    int t;
    ll n,ans;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%lld",&n);
            ans=(power_mod(4,n-1)%MOD+power_mod(2,n-1)%MOD)%MOD;
            printf("%lld\n",ans);
        }
    }
}

