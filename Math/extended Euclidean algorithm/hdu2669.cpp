#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll temp=x;
    x=y;
    y=temp-a/b*y;
    return;
}
int main()
{
    ll a,b,x,y;
    while(scanf("%I64d%I64d",&a,&b)!=EOF){
        if(gcd(a,b)!=1){
            printf("sorry\n");
        }
        else{
            exgcd(a,b,x,y);
            if(x<0){
                x+=b;
                y-=a;
            }
            printf("%I64d %I64d\n",x,y);
        }
    }
    return 0;
}
