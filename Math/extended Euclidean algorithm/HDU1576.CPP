#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll temp=x;
    x=y;
    y=temp-a/b*y;
    return;
}
int main()
{
    ll n,b,t,x,y;
    while(scanf("%I64d",&t)!=EOF){
        while(t--){
            scanf("%I64d%I64d",&n,&b);
            exgcd(b,9973,x,y);
            x=((n*x)%9973+9973)%9973;
            if(x<0){
                x+=9973;
            }
            printf("%I64d\n",x);
        }
    }
}
