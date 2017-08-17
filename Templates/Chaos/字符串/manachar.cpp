int manacher()
{    
	int i,p,ans=0;
    r[1]=0,p=1;
    for (i=2;i<=n;++i)
    {    if (i<=p+r[p])
            r[i]=min(r[2*p-i],p+r[p]-i);
        else r[i]=1;
        while (st[i-r[i]]==st[i+r[i]])
            ++r[i];
        --r[i];
        if (i+r[i]>p+r[p])
            p=i;
        ans=max(ans,r[i]);
    }
    return ans;
}
