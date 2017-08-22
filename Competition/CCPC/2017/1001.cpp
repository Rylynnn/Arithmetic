/*************************************************************************
    > File Name: 1001.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月19日 星期六 15时26分16秒
 ************************************************************************/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t, len, n, num, l, r, tmp, ans;
    scanf("%ld:wq
            d", &t);
    while(t--){
        scanf("%lld", &n);
        len = sqrt(n / 2), l = len * len * 2, r = (len+1) * (len+1) * 2, tmp = r - l;
        if(n == 1 || n == 2){
            ans = 4;
        }
        if(n == l){
            ans = 4 * len;
        }
        else if(n - l <= len - 1){
            ans = 4 * len + 1;
        }
        else if(n - l < tmp / 2){
            ans = 4 * len + 2;
        }
        else if(n - l <= tmp / 2 + len - 1){
            ans = 4 * len + 3;
        }
        else{
            ans = 4 * len + 4;
        }
        printf("%lld", ans);
    }
    return 0;
}
