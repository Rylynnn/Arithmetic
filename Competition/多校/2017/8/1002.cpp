/*************************************************************************
    > File Name: 1002.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月17日 星期四 13时30分44秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
using namespace std;
int gcd(int a, int b){
    return b == 0 ? a :gcd(b, a%b);
}
int main()
{
    int n, ans, ansb;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        ans = ansb;
        for(int k=1; k<=i; k++){
            if(gcd(i, k) == 1){
                ans += (int)(ceil((double)i / k)) % MOD;
            }
        }
        ansb = ans % MOD;
        cout << ans % MOD << ',';
    }
    return 0;
}
