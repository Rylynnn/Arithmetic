#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll,ll> h;
int main()
{
    ll p,u,v,w,oby,ans;
    while(scanf("%I64d",&p)!=EOF){
        while(p--){
            scanf("%I64d",&oby);
            if(oby==1){
                scanf("%I64d%I64d%I64d",&v,&u,&w);
                while(u!=v){
                    if(u>v){
                        h[u]+=w;
                        u>>=1;
                    }
                    else{
                        h[v]+=w;
                        v>>=1;
                    }
                }
            }
            else{
                ans=0;
                scanf("%I64d%I64d",&v,&u);
                while (u!=v){
                    if(u>v){
                        ans+=h[u];
                        u>>=1;
                    }
                    else{
                        ans+=h[v];
                        v>>=1;
                    }
                }
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
