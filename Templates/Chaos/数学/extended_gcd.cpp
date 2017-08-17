LL extended_gcd(LL a,LL b,LL &x,LL &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        LL r=extended_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
