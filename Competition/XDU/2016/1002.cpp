/*
wa:2和3的情况均是1 1
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
void multiply(long long c[2][2],long long a[2][2],long long b[2][2])
{
    long long tmp[4];
    tmp[0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    tmp[1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    tmp[2]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    tmp[3]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
    c[0][0]=tmp[0];
    c[0][1]=tmp[1];
    c[1][0]=tmp[2];
    c[1][1]=tmp[3];
}
long long fibonacci(long long n)
{
    if(n==0LL)return 0LL;
    else if(n<=2LL)return 1LL;

    long long a[2][2]= {{1,1},{1,0}};
    long long result[2][2]= {{1,0},{0,1}};
    long long s;
    n-=2LL;
    while(n>0)
    {
        if(n%2LL == 1LL)
            multiply(result,result,a);
        multiply(a,a,a);
        n /= 2LL;
    }
    s=(result[0][0]+result[0][1]);
    return s;
}
int main()
{
    long long n,ans,num;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n==3||n==2)
        {
            printf("1 1\n");
        }
        else
        {
            num=1;
            ans=fibonacci(num);
            while(ans<=n)
            {
                if(ans+fibonacci(num+1)>n)
                {
                    if(n-ans>fibonacci(num))
                    {
                        printf("%lld %lld\n",num+1,n-ans);
                    }
                    else
                    {
                        printf("%lld %lld\n",num,fibonacci(num));
                    }
                    break;
                }
                else if(ans+fibonacci(num+1)==n)
                {
                    printf("%lld %lld\n",num+1,fibonacci(num+1));
                    break;
                }
                else
                {
                    num++;
                    ans+=fibonacci(num);
                }
            }
        }
    }
    return 0;
}
