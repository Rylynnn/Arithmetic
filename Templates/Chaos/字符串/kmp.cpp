void getnext(int t[],int m)
{    
	int i,j;
    i=0,j=1;
    kmpnext[1]=0;
    while (j<=m)
        if (i==0||t[i]==t[j])
        {    ++i,++j;
            kmpnext[j]=i;
        }
        else i=kmpnext[i];
}
int kmp(int s[],int t[],int n,int m)
{    
	int i,j;
    j=0;
    for (i=1;i<=n;i++)
	{
		while (j>0&&t[j+1]!=s[i])) j=kmpnext[j];
		if (t[j+1]==s[i]) j++;
		if (j==m)
		{
			return i-m+1;
		}
	}
    return -1;
}
