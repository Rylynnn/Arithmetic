#include <bits/stdc++.h>
#define eps 1e-6
#define MAX 100007
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    while(scanf("%I64d%I64d",&m,&n)!=EOF){
        if(((m+1)/2)*(m/2)<=n){
            printf("T\n");
        }
        else{
            printf("F\n");
        }
    }
    return 0;
}
