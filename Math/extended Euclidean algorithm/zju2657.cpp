#include <cstdio>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll& x,ll& y){
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
    ll a,b,c,m,n,x,y,l,t,k,ans;
    while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)!=EOF){
        a=n-m;
        b=l;
        c=x-y;
        t=gcd(a,b);
        if(c%t!=0){
            printf("Pat\n");
        }
        else{
            a/=t;
            b/=t;
            c/=t;
            exgcd(a,b,x,y);//printf("%lld\n",x);
            if(b<0){//周期为正
                b=-b;
            }
            x=((x*c)%b+b)%b;
            //ans=(x+(k%l)*(m%l)%l)%l;
            if(x<0){
                x+=b;
            }
            printf("%lld\n",x);
        }
    }
    return 0;
}
