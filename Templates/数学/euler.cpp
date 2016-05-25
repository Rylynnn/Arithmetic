int minDiv[maxn],phi[maxn];
void getPhi()
{
	for (int i=1;i<maxn;i++)
	  minDiv[i]=i;
	for (int i=2;i*i<maxn;i++)
	{
		if (minDiv[i]==i)
		{
			for (int j=i*i;j<max;j+=i)
			  minDiv[j]=i;
	    }
    }
    phi[1]=1;
    for (int i=2;i<max;i++)
    {
		phi[i]=phi[i/minDiv[i]];
		if ((i/minDiv[i])%minDiv[i]==0)  phi[i]*=minDiv[i];
	    else phi[i]*=minDiv[i]-1;
    }
}
LL phi(LL n)  
{  
    LL i;  
    LL result = n;  
    LL t = (LL)sqrt(n*1.0);  
    for(i = 2; i <= t; i++)  
    {  
        if(n%i==0)  
        {  
            result = result/i*(i-1);  
            while(n%i==0)  
                n = n/i;  
        }  
    }  
    if(n>1)  
        result = result/n*(n-1);  
    return result;  
} 
LL phi(LL n)  
{  
    LL res=n;  
    for(int i=1;prim[i]*prim[i]<=n&&i<=primm;i++)  
    {  
        if(n%prim[i]==0)  
        {  
            res=res-res/prim[i];  
            while(n%prim[i]==0)  n/=prim[i];  
        }  
    }  
    if(n>1)  
      res=res-res/n;  
    return res%p;  
}  
