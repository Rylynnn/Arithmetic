#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll&y){
    if(b==0){
        x=1,y=0;
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
    ll a,b,c,k,t,x,y,p,q,n;
    ll two[40];
    two[0]=1;
    two[1]=2;
    for(int i=1;i<=32;i++){
        two[i]=two[i-1]*2;
        //cout<<two[i];
    }
    while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&k),a+b+c+k){
        p=c;
        q=two[k];
        n=b-a;
        t=gcd(p,q);
        if(n%t!=0){
            printf("FOREVER\n");
        }
        else{
            ll temp;
            p/=t;
            q/=t;
            n/=t;
            exgcd(p,q,x,y);
            x=((n*x)%q+q)%q;
            //cout<<x<<' ';
            if(x<0){
                x+=q;
            }
            printf("%I64d\n",x);
        }
    }
    return 0;
}
