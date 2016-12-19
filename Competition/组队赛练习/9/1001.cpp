#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MOD 1000000007
using namespace std;
typedef long long LL;
int main()
{
    long long k,p;
    while (scanf("%I64d%I64d",&k,&p)!=EOF) {
        printf("%s\n",((k/(p-1))&1)==1?"YES":"NO");
    }
    return 0;
}
