/*************************************************************************
    > File Name: b.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 三  9/ 6 21:10:36 2017
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, a, b;
    cin >> n >> k;
    if(k == 0 || n == k || n == 0){
        a = 0;
        b = 0;
    }
    else{
        a = 1;
        b = min(n-k, k*2);
    }
    cout << a << ' ' << b << endl;
    return 0;
}
