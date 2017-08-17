LL multi(LL a, LL b)
{
    LL ret=0;
    while(b)
	{
        if(b&1) ret=(ret+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return ret;
}
