LL extended_bsgs(LL a,LL b,LL n)
{
    LL t,c=0,v=1;  
    while ((t=gcd(a,n))!=1)
	{  
        if (b%t)  
            return -1;  
        n/=t;  
        b/=t;  
        v=v*a/t%n;  
        c++;  
        if (b==v) return c;  
    }
	LL x,y;
	extended_gcd(v,n,x,y);  
    b=b*x%n;  
    LL ret=bsgs(a,b,n);  
    return ~ret ? ret+c:ret;  
}  

