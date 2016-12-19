#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a>b){
            swap(a,b);
        }
        printf("%I64d",((long long)a*(long long)b)/(long long)gcd(a,b));
    }
}
