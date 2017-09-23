/*************************************************************************
    > File Name: a.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/17 21:01:38 2017
 ************************************************************************/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, k;
    cin >> n >> k;
    ll num = n;
    ll now = pow(10, k);
    while(num % now != 0){
        num += n;
    }
    cout << num;
    return 0;
}

