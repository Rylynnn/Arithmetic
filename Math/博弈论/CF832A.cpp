/*************************************************************************
    > File Name: CF832A.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月05日 星期六 19时43分49秒
 ************************************************************************/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, k;
    while(scanf("%I64d%I64d", &n, &k)!=EOF){
        if(n / k % 2 == 0){
           printf("NO\n");
        }
        else{
           printf("YES\n");
        }
    }
    return 0;
} 
