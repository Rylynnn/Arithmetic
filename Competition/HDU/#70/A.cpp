#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    long long a,b,c,d,e,f,t;
    long long num;
    scanf("%I64d",&t);
    while(t--) {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        num=b*b-4*a*c;
        if(num>=0&&sqrt(num)*sqrt(num)==num) {
                if((2*a)*(-(-b+sqrt(num)))>0&&(2*a)*(-(-b-sqrt(num)))>0)
                printf("YES\n");
                else{
                    printf("NO\n");
                }
        }
        else {
                printf("NO\n");

        }
    }
return 0;
}

