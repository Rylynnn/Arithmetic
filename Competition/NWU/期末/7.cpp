#include <stdio.h>
long long   pow_mod(long long   a,long long n)
{
    long long  ret = 1;
    long long  temp = a;
    while(n)
    {
        if(n & 1)ret = ret*a;
        a*=a;
        n >>= 1;
    }
    return ret;
}
int  main()
{
    long long  a,b,x,ans;
    while(scanf("%I64d%I64d%I64d",&a,&b,&x)!=EOF) {
        ans=0;
        ans=pow_mod(a,b);
        //printf("%I64d\n",ans);

        printf("%I64d\n",ans%pow_mod(10,x));
    }
    return 0;
}

