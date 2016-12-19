#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n;
    ll a[107],b[107];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d/%d",&a[i],&b[i]);

    }
}
