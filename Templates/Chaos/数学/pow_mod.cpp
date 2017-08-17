LL pow_mod(LL a,LL b)
{
    LL ret=1;
    while(b)
	{
        if(b&1) ret=multi(ret,a)%p;
        a=multi(a,a)%p;
        b>>=1;
    }
    return ret;
}

