#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MOD 10000000007
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
LL pow_mod(LL a,LL i,LL n)
{
	if (a==0) return 0;
	if (i==0) return 1LL;
	LL temp=pow_mod(a,i>>1,n);
	if(temp*temp>n)MM=1;
    temp=temp*temp%n;
    if (i&1){
            if(temp*a>n){
                MM=1;
            }
            temp=temp*a%n;
    }
    return temp;
}
int main()
{
    while (cin>>a>>b>>c>>y)
	{
	    if(y==1){
            cout<<0<<endl;
	    }
	    else if(gcd(a,y)==1){
            LL p=phi(y);
            LL kk=pow_mod(b%p,c,p);
            LL ans=pow_mod(a%y,kk,y);
            cout<<ans<<endl;
        }
		else{
             LL p=phi(y);
             LL kk=pow_mod(b%p,c,p);
             MM=0;
            LL ans=pow_mod(a%y,(MM==1)?kk+p:kk,y);
            cout<<ans<<endl;
		}
	}
	return 0;
}
