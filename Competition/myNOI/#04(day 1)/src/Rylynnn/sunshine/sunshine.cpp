#include <bits/stdc++.h>
#define MAXN 10000007
#define MOD 1000000007
#define ll long long
using namespace std;
ll pow_mod(ll m,ll c,ll k) {
    ll b=1;
    while(c>0){
        if(c&1)
            b=(b*m)%k;
        c=c>>1 ;
        m=(m*m)%k;
    }
    return b;
}
int main()
{
    ll n,m,p,a[50007];
    scanf("%I64d%I64d%I64d",&n,&m,&p);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*((m*pow_mod(m-1,a[i]-1,p))%p)%p;
    }
    printf("%I64d",ans);
    return 0;
}
