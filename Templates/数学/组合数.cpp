{
	C[0][0]=1;
    for(int i=1;i<=31;i++){
		C[i][0]=1;
        for (int j=1;j<=i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
}

LL C(int n,int m)
{
	LL res=(f[n]*inv[m])%mod;
	res=(res*inv[n-m])%mod;
	return res;
}
{
	f[0]=1;
	for (int i=1;i<=1000010;i++)
		f[i]=(f[i-1]*i)%mod;
	ff[1]=ff[0]=inv[1]=inv[0]=1;  
	for (int i=2;i<=1000010;i++)
	{
    	inv[i]=(LL)(mod-mod/i)*inv[mod%i]%mod;
    	ff[i]=inv[i];
	}
	for (int i=2;i<=1000010;i++)
		inv[i]=(inv[i-1]*inv[i])%mod;
}
