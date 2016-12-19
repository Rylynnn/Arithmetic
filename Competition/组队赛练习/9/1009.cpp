#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MOD 1000000009
#define MAX 100007
using namespace std;
typedef long long ll;
ll f[100007];
ll n,m;
void getset(){
    f[0]=1;
    for(int i=1;i<MAX;i++){
        f[i]=(f[i-1]*i)%MOD;
    }
}
ll pow_mod(ll m,ll n,ll k) {
    ll b = 1;
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
    ll minm,maxm,mm,mn,ans,x;
    getset();
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        maxm=minm=0;
        for(int i=0;i<n;i++){
            scanf("%I64d",&x);
            if(x+maxm<=m){
                mm=x+maxm;
            }
            else if(minm+x<=m){
                mm=((minm+x)%2==(m%2))?m:m-1;
            }
            else{
                mm=m*2-(minm+x);
            }
            if(minm>=x){
                mn=minm-x;
            }
            else if(maxm>=x){
                mn=((minm%2)==(x%2))?0:1;
            }
            else{
                mn=x-maxm;
            }
            maxm=mm;
            minm=mn;
        }
        ans=0;
        //cout<<m;
        for(int i=minm;i<=maxm;i+=2){
            ans+=((f[m]%MOD)*(pow_mod(((f[i]%MOD)*(f[m-i]%MOD))%MOD,MOD-2,MOD)%MOD))%MOD;
        }
        printf("%I64d\n",ans%MOD);
    }
}
