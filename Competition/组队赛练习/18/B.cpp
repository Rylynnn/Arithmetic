#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <iostream>
#define ll long long
using namespace std;
map<ll,string>num;
int main() {
    int T, kase = 0;
    ll n,k;
    scanf("%d", &T);
    while(kase < T) {
        scanf("%I64d%I64d", &n, &k);
        for(int i=0;i<k;i++){
            num[1LL<<i]="+";
        }
        ll now;
        if(n&1==1LL){
            now=(1LL<<k)+1LL-n;
        }
        else{
            now=(1LL<<k)-n;
        }
        now/=2LL;
        ll p=1LL;
        if(n&1==1LL){
            now--;
        }
        while(now){
            if((now&1LL)==1LL){
                num[p]="-";
            }
            now>>=1LL;
            p*=2LL;
        }
        printf("Case #%d:\n", ++kase);
        for(ll i=0;i<k-1;i++){
            printf("%I64d ",(1LL<<i));
            cout<<num[1<<i]<<"\n";
        }
        if(n&1==1){
            printf("%I64d ",(1LL<<(k-1)));
            cout<<"+"<<"\n";
        }
        else{
            printf("%I64d ",(1LL<<(k-1))+1);
            cout<<"+"<<"\n";
        }
    }
    return 0;
}
