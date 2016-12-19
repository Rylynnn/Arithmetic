#include <bits/stdc++.h>
#define N 1e18+100//最大值不能直接为1e18，不然可能会造成找不到大于等于1e18只包含2,3,5因子的数
#define ll long long
using namespace std;
int main()
{
    set<ll> ans;
    for(ll i=1;i<N;i*=2){
        for(ll j=1;i*j<N;j*=3){
            for(ll k=1;i*j*k<N;k*=5){
                ans.insert(i*j*k);
            }
        }
    }
    ll n,t;
    while(scanf("%I64d",&t)!=EOF){
        while(t--){
            scanf("%I64d",&n);
            if(n==1){
                printf("2\n");
            }
            else{
                printf("%I64d\n",*ans.lower_bound(n));
            }
        }
    }
    return 0;
}
