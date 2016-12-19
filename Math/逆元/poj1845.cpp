#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#define MAXN 10007
#define MOD 9901
#define ll long long
using namespace std;
ll check[MAXN],prime[MAXN];
ll getprime(){
    ll tot=0;
    memset(check,false,sizeof(check));
    check[0]=check[1]=true;
    for(int i=2;i<MAXN;i++){
        if(!check[i]){
            prime[tot++]=i;
            for(int j=i<<1;j<MAXN;j+=i){
                check[j]=true;
            }
        }
    }
    return tot;
}
ll getprime_Euler(){
    ll tot=0;
    memset(check,false,sizeof(check));
    check[0]=check[1]=true;
    for(int i=2;i<MAXN;i++){
        if(!check[i]){
            prime[tot++]=i;
        }
        for(int j=0;j<tot;j++){
            if(i*prime[j]>MAXN){
                break;
            }
            check[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    return tot;
}
ll mul_mod(ll a,ll b,ll m){//wa:mul_mod写错了。。。
    ll ans=0;
    a%=m;
    while(b>0){
        if(b&1){
            ans+=a;
            ans%=m;
        }
        b=b>>1;
        a+=a;
        a%=m;
    }
    return ans;
}
ll pow_mod(ll a,ll b,ll m){
    ll ans=1;
    a%=m;
    while(b>0){
        if(b&1){
            ans=mul_mod(ans,a,m)%m;
        }
        b=b>>1;
        a=mul_mod(a,a,m)%m;
    }
    return ans;
}
int main()
{
    ll a,b,m,num,ans;
    ans=1;
    ll tot=getprime_Euler();
    scanf("%lld%lld",&a,&b);
    for(int i=0;prime[i]*prime[i]<=a;i++){
        if(a%prime[i]==0){
            num=0;
            while(a%prime[i]==0){
                num++;
                a/=prime[i];
            }
            if((prime[i]-1)%MOD==0){
                /* 如果此时prime[i]-1是素数9901的整数倍，假设a,则 (a-1) mod 9901 = 0
                a^0 + a^1 + a^2 + ... + a^n = 1 + ... + (a-1)^n + (a-1)^(n-1) + ... + (a-1)^0 = n + 1
                所以可以得出以下式子
                */
                ans=(ans*((num*b+1)%MOD))%MOD;
            }
            else{
                m=MOD*(prime[i]-1);
                //cout<<m<<endl;
                ans=ans*((pow_mod(prime[i],num*b+1,m)+m-1)/(prime[i]-1))%MOD;
            }
        }
    }
    if(a!=1){
        if((a-1)%MOD==0){
            ans=(ans*((b+1)%MOD)%MOD);
        }
        else{
            m=MOD*(a-1);
            //cout<<m<<endl;
            ans=ans*((pow_mod(a,b+1,m)+m-1)/(a-1))%MOD;
        }
    }
    printf("%lld\n",(ans+MOD)%MOD);
}
