inv[1]=1;  
for (int i=2;i<=1000000;i++)
    inv[i]=(LL)(mod-mod/i)*inv[mod%i]%mod;

