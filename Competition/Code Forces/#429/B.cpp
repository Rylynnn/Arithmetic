/*************************************************************************
    > File Name: B.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月18日 星期五 23时25分27秒
 ************************************************************************/
#include <bits/stdc++.h>
#define ll int
using namespace std;
ll n, a[1000007], num1, num2, sum[1000007];
int main()
{
    scanf("%d", &n);
    memset(sum, 0, sizeof(sum));
    memset(a, 0, sizeof(a));
    num1 = 0, num2 = 0;
    for(int i=1; i<=n; i++){
        scanf("%d",  &a[i]);
        sum[i] = sum[i-1] + a[i];
        if(sum[i] % 2 == 1){
            num1++;
        }
        else{
            num2++;
        }
    }
    cout << sum[n];
    if(sum[n] % 2 == 1){
        cout << "First" << endl;
    }
    else if(sum[n] % 2 == 0){
        if(num1 != 0){
            cout << "First" << endl;
        }
        else{
            cout << "Second" << endl;
        }
    }

    return 0;
}
