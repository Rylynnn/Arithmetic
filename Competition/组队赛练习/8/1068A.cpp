#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int t,a,b,k,m[10007],f[10007];
ll getnum(ll num){
    ll i,j,ans=0;
    j=b-1;
    for(i=0;i<a;i++){
        for(;j>=0&&m[i]*f[j]>num;j--){
            ans+=b-1-j;
        }
    }
    return ans;
}
int main()
{

    ll l,r,num,mid;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d%d%d",&a,&b,&k);
            for(int i=0;i<a;i++){
                scanf("%d",&m[i]);
            }
            for(int i=0;i<b;i++){
                scanf("%d",&f[i]);
            }
            sort(m,m+a);
            sort(f,f+b);
            l=1;
            r=m[a-1]*f[b-1];
            while(l<=r){
                mid=(l+r)<<1;
                num=getnum(mid);
                if(num<=k){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
                cout<<l<<' '<<r<<endl;
            }
            printf("%lld\n",r+1);
        }
    }
    return 0;
}
