#include<iostream>
#include<algorithm>
#include<cstring>
#include <cstdio>
using namespace std;
char a[100000];
char b[100000];
int  ha[26];
typedef long long LL;
LL pow_mod(LL a,LL i,LL n)
{
	if (a==0) return 0;
	if (i==0) return 1LL;
	LL temp=pow_mod(a,i>>1,n);
    temp=temp*temp%n;
    if (i&1) temp=temp*a%n;
    return temp;
}
int main(){
 cout<<pow_mod(4,64,28);
}
