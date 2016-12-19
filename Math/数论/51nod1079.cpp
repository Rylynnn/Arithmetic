#include <bits/stdc++.h>
#define ll long long
using namespace std;
void ex_gcd(ll a,ll b,ll &x,ll &y){
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
ll CRT(ll a[],ll m[],ll n){
    ll M=1,ans=0;
    for(int i=0;i<n;i++){
        M*=m[i];
    }
    for(int i=0;i<n;i++){
        ll x,y;
        ll Mi=M/m[i];
        ex_gcd(Mi,m[i],x,y);
        ans=(ans+a[i]*Mi*x)%M;
    }
    if(ans<0){
        ans+=M;
    }
    return ans;
}
int main()
{
    ll n,ans,p[17],m[17];
    while(scanf("%I64d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%I64d%I64d",&m[i],&p[i]);
        }
        ans=CRT(p,m,n);
        printf("%I64d\n",ans);
    }
}
