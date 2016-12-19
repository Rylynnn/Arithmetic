#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll l1,l2,r1,r2,k,ans;
    while(scanf("%I64d%I64d%I64d%I64d%I64d",&l1,&r1,&l2,&r2,&k)!=EOF){
        ans=0;
        if(r1<l2||l1>r2){
            printf("0\n");
            fflush(stdout);
        }
        else{
            ans=min(r1,r2)-max(l1,l2)+1;
            if(k>=max(l1,l2)&&k<=min(r1,r2)){
                ans--;
            }
            printf("%I64d\n",ans);
            fflush(stdout);
        }
    }
    return 0;
}
