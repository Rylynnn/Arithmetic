#include <bits/stdc++.h>
#define ll long long
#define N 1e18
using namespace std;
int main()
{
    ll x1,x2,y2,y1,ny1,ny2,l,r,rr,ans=0;
    scanf("%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2);
    if(x1==x2&&y1==y2){
        printf("1\n");
        return 0;
    }
    r=abs((y2-y1)/2+1);
    l=abs((x2-x1)+1);
    ans=r;
    if(l>1){
        rr=abs((y2-y1)/2);
    }
    if(l>1){
        ans+=(l/2)*(r+rr);
    }
    printf("%I64d",ans);
    return 0;
}
