#include<cstdio>
#define INF 1000000007
long long quickpow(long long m,long long n,long long k)
{
    long long b = 1;
    while (n > 0)
    {
          if (n & 1)
             b = (b*m)%k;
          n = n >> 1 ;
          m = (m*m)%k;
    }
    return b;
}
int main() {
    int t;
    long long n;
    while(~scanf("%d",&t)) {
        while(t--){
            scanf("%I64d",&n);
            printf("%I64d\n",quickpow(2,n-1,INF)-1);
        }
    }
    return 0;
}
