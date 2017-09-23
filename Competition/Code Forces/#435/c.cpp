/*************************************************************************
    > File Name: c.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 三  9/20 00:22:04 2017
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, ans = 0;
    cin >> n >> x;
    cout << "YES" << endl;
    int num = n % 4;
    if(num == 1){
        cout << x;
        ans ^=x;
    }
    else if(num == 2){
        cout << 0 << ' ' << x;
        ans ^= x^0;
    }
    else if(num == 3){
        cout << 3 << ' ' << 2 << ' ' << (x^1);
        ans ^= (3^2^(x^1));
    }
    else if(num == 4){
        cout << 0 << ' ' << 2 << ' ' << 3 << ' ' << (x^1);
        ans ^= (3^2^(x^1));
    }
    int cnt = n / 4;

    for(int i=1; i<=cnt; i++){
        int a, b, c, d;
        a = 4 * (i+500000);
        b = a + 1;
        c = a + 2;
        d = a + 3;
        ans ^= (a^b^c^d);
        cout << ' ' << a << ' ' << b << ' ' << c << ' ' << d ;
    }
    cout << endl;
    return 0;
}
