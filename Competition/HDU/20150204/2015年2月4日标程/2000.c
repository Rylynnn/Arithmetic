#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LOCAL
__int64 sum,k;
__int64 fun(int m,int n)
{
	__int64 s=1;
	int i;
	for(i=1;i<n;i++)
		s*=m-1;
	if(s<0) s=0;
	return s;
}


__int64 func(int m,int n)
{
	if(n==1)
		return 0;
	else
	{
        k=-k;
		__int64 t=k*fun(m,n);//(__int64)pow(m-1,n-1);
		return sum=func(m,n-1)+t;
	}
}
int main()
{
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif // LOCAL
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		sum=0;
		k=-1;
	    if(m<=1||n<=1)
		{  printf("data is error!"); exit(-1);}
	    func(m,n);
	    printf("%I64d\n",sum);
	}
	return 0;
}
