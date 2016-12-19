#include <bits/stdc++.h>
#define ll long long
using namespace std;
void ex_gcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    ex_gcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-(a/b)*y;
    return;
}
int main()
{
    ll m,n;
    while(scanf("%I64d%I64d",&m,&n)!=EOF){
        ll x,y;
        ex_gcd(m,n,x,y);
        if(x<0){
            x+=n;
        }
        printf("%I64d\n",x);
    }
}
