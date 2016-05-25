#include <cstdio>
long long gcd(long long a,long long b)
{return b==0?a:gcd(b,a%b);}
void exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    long long temp=x;
    x=y;
    y=temp-a/b*y;
    return;
}
int main()
{
    long long x,y,m,n,t,l,ans,a,b,c,d;
    while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)!=EOF){
        ans=x-y;
        a=n-m;
        b=l;
        t=gcd(a,b);
        if(ans%t!=0||m==n){
            printf("Impossible\n");
        }
        else{
            a/=t;
            b/=t;
            ans/=t;
            exgcd(a,b,c,d);
            c=((ans*c)%b+b)%b;
            if(c<0){
                c+=b;
            }
            printf("%lld\n",c);
        }
    }
    return 0;
}
