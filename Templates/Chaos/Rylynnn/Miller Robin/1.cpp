/* *************************************************
* Miller_Rabin 算法进行素数测试
* 速度快，可以判断一个 < 2^63 的数是不是素数
*
**************************************************/
//10e6:time:9.461s number:78491
//10e6-10e7:time:107.8s number:586081
#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int S = 8;
LL mult_mod(LL  a,LL   b,LL   c)
{
	a %= c;
	b %= c;
	LL ret = 0;
	LL tmp = a;
	while(b)
	{
		if(b & 1)
		{
        ret += tmp;
        if(ret > c)ret -= c;
		}
        tmp <<= 1;
        if(tmp > c)tmp -= c;
        b >>= 1;
	}
	return ret;
}
LL  pow_mod(LL   a,LL   n,LL   mod)
{
	LL ret = 1;
	LL temp = a%mod;
	while(n)
	{
		if(n & 1)ret = mult_mod(ret,temp,mod);
		temp = mult_mod(temp,temp,mod);
		n >>= 1;
	}
	return ret;
}
bool check(LL a,LL n,LL x,LL t)
{
	LL ret = pow_mod(a,x,n);
	LL last = ret;
	for(int i = 1;i <= t;i++)
	{
	ret = mult_mod(ret,ret,n);
	if(ret == 1 && last != 1 && last != n-1)return true;
	last = ret;
	}
	if(ret != 1)return true;
	else return false;
}
bool MiLLer_Rabin(LL n)
{
	if( n < 2)return false;
	if( n == 2)return true;
	if( (n&1) == 0)return false;
	LL x = n - 1;
	LL t = 0;
	while( (x&1)==0 ){x >>= 1; t++;}
	srand(time(NULL ));
	for(int i = 0;i < S;i++)
	{
		LL a = rand()%(n-1) + 1;
		if( check(a,n,x,t) )
		return false;
	}
	return true;
}
int main()
{
    int T;
    freopen("Prime10e6-10e7.txt","w",stdout);
    LL num,a,i;
    a=1000000;
    num=0;
    printf("2");
    for(i=1000000;i<=10000000;i++){
        if(MiLLer_Rabin(i)){
            num++;
            printf(" %I64d",i);
        }
    }
    printf("\n");
    printf("%I64d",num);
    return 0;
}
