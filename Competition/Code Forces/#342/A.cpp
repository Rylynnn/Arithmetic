#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long gc,n,a,b,c,num;
    while(scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&c)!=EOF) {
        if(a<=b-c||n<b){
            printf("%I64d\n",n/a);
        }
        else{
            printf("%I64d\n",(n-b)/(b-c)+1+((n-b)%(b-c)+c)/a);
        }
    }
    return 0;
}


