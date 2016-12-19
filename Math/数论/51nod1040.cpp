/*
打表发现当n为合数的时候，1~n之间与n的最大公约数是对称的
发现这个不通，然后写一写公式发现其实是求phi（n/d）d是n的因子
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll phi(ll n){
    ll temp=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            temp=temp/i*(i-1);
        }
        if(n<i+1){
            break;
        }
    }
    if(n>1){
        temp=temp/n*(n-1);
    }
    return temp;
}
int main()
{
    ll n,ans;
    while(scanf("%I64d",&n)!=EOF){
        ans=0;
        ll tmp=n;
        //prllf("%d",ans);
        for(ll i=1;i*i<=tmp;i++){
            if(tmp%i==0){
                if(i*i!=tmp){
                    ans+=phi(i)*(tmp/i);
                }
                ans+=phi(tmp/i)*i;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
