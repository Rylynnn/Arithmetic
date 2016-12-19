#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll p,a;
    vector<ll> ans;
    while(scanf("%I64d%I64d",&p,&a)!=EOF){
        ans.clear();
        for(ll i=0;i<=p;i++){
            if((i*i)%p==a){
                ans.push_back(i);
            }
        }
        if(ans.size()!=0){
            printf("%I64d",ans[0]);
            for(ll i=1;i<ans.size();i++){
                printf(" %I64d",ans[i]);
            }
            printf("\n");
        }
        else{
            printf("No Solution\n");
        }
    }
}
