LL findprimitiveroot(LL x)
{
	for (LL i=2;i<=x;i++)
	{
		LL flag=0,now=1;
		for (int j=1;j<=x-1;j++)
		{
			now=(now*LL(i))%x;
			if (now==1)
			{
				flag=1;
				break;
			}
		}
		if (flag==0) return i;
	}
}
