#include <bits/stdc++.h>
#define eps 1e-6
#define MAX 100007
#define ll long long
using namespace std;
int main()
{
    ll t,n,a[20007];
    while(scanf("%I64d",&t)!=EOF){
        while(t--){
            ll sum=0,p=0,num=0;
            scanf("%I64d",&n);
            for(ll i=1;i<=n;i++){
                scanf("%I64d",&a[i]);
                if(a[i]&1){
                    num++;
                }
                if(a[i]>=(2*n-1)){
                    p=1;
                }
                sum+=a[i];
            }
            if(sum!=n*(n-1)){
                p=1;
            }
            if(num&1){
                p=1;
            }
            if(p==0){
                printf("T\n");
            }
            else{
                printf("F\n");
            }
        }
    }
    return 0;
}
