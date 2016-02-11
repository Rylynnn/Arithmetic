//设有n<=10000条封闭曲线画在平面上，而任何两条封闭曲线恰好相交于两点，
//且任何三条封闭曲线不相交于同一点，问这些封闭曲线把平面分割成的区域个数。
//F(1)=2
//F(n)=F(n-1)+2(n-1)
//递归实现：
/*
#include<stdio.h>
int fun(int n)
{
	if(n==1) return 2;
	else return fun(n-1)+2*(n-1);
}
int main()
{
	int n;
	while(scanf("%d",&n))
	{
	int sum=fun(n); 
	printf("%d\n",sum);
	}
	return 0;
}
//非递归实现(预处理)：
*/
#include<stdio.h>
#define maxn 10000
__int64 a[maxn]={0,2};
int main()
{
	int n;
	for(int i=2;i<=10000;i++)
		a[i]=a[i-1]+2*(i-1);
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",a[n]);
	}
}
