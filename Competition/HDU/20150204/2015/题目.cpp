/*为了备战即将到来的世界杯预选赛，中国队的王大雷、郑智、张琳芃、孙可等
  m(1<m<=11)个人相互传球训练，第一次由孙可传给王大雷、郑智、张琳芃等中的任一人，
  第二次由拿球者再传给其他人中任一人，这样总共传了n(1<n<=10)次，则第n次球仍传回
  到孙祥方法共有几种？
  input
  2 2
  3 2
  output
  1
  2
*/
/*设不同的传球方法共有a(n)种，现在我们来通过合理分步，恰当分类找出递推关系：
  第一步进行第一次传球：甲传给其他人，有m-1种传球方法；
  第二步进行第二次传球：拿球者把球传给其他人，仍有m-1种传球方法；
  同理，第三次、第四次、……、第n-1次传球都有m-1种传球方法，最后进行第n
  次传球，由于只能传给甲，故只有一次传球方法，相乘得(m-1)^(n-1)种传球方法，
  但要注意第n-1次传球不能传给甲，否则就不存在第n次传球，因此要去掉第n-1次传球，
  球恰好传给甲的传球方法数，这就是由甲先传，经过n-1次传球后球又回到甲手中的
  传球方法，显然，这里有a(n-1)种传球方法，所以有递推关系：
     a(n)=(m-1)^(n-1)-a(n-1),a(1)=0
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
__int64 sum,k;
__int64 fun(int m,int n)
{
	__int64 s=1;
	for(int i=1;i<n;i++)
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
