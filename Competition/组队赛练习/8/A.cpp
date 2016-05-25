#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL MM;
LL gcd(LL a,LL b){
    return (b>0)?gcd(b,a%b):a;
}
LL phi(LL n)
{
    LL i;
    LL result = n;
    LL t = (LL)sqrt(n*1.0);
    for(i = 2; i <= t; i++)
    {
        if(n%i==0)
        {
            result = result/i*(i-1LL);
            while(n%i==0)
                n = n/i;
        }
    }
    if(n>1LL)
        result = result/n*(n- 1LL);
    return result;
}
LL a,b,c,y;
LL pow_mod(LL m,LL n,LL k) {
    LL b = 1;
    while (n > 0) {
        if (n & 1)
            b = (b*m)%k;
        n = n >> 1 ;
        m = (m*m)%k;
    }
    return b;
}

int main()
{
    LL p,ans,a,b,n,bn,t;
    p=phi(MOD);
    //cout<<p;
    while (scanf("%lld",&t)!=EOF){
        while(t--){
            scanf("%lld%lld%lld",&a,&n,&b);
            ans=pow_mod(a%MOD,b%p,MOD);
            //cout<<ans<<' ';
            for(LL i=1;i<n;i++){
                bn=((b%p)*(b%p))%p-1;
                ans=pow_mod(ans%MOD,bn%p,MOD);
                b=bn;
                //cout<<bn<<' '<<ans;
            }
            cout<<ans<<endl;
        }
	}
	return 0;
}
