#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long a1,b1,a2,b2;
    while(scanf("%lld+%lldi %lld+%lldi",&a1,&a2,&b1,&b2)!=EOF){
        printf("%lld+%lldi\n",a1+b1,a2+b2);
    }
    return 0;
}
