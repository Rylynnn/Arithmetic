int extended_crt(int n,LL m[],LL r[])  
{  
    LL m1,r1,m2,r2,d,x,y,c,t;
	int flag=0;
    m1=m[1],r1=r[1];  
    flag=0;  
    for(int i=2;i<=n;i++)  
    {  
        m2=m[i],r2=r[i]; 
        d=extended_gcd(m1,m2,x,y);  
        c=r2-r1;  
        if(c%d) 
        {  
            flag=1;  
            break;  
        }  
        t=m2/d; 
        x=(c/d*x%t+t)%t;  
        r1=m1*x+r1;
        m1=m1*m2/d;  
    }  
    if(flag)return -1; 
    else return r1;  
}  
