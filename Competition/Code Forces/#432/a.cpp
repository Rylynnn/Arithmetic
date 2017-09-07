/*************************************************************************
    > File Name: a.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 一  9/ 4 22:15:47 2017
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
    int n, k, t;
    cin >> n >> k >> t;
    if(n <= k){
        if(t <= k && t <= n){
            cout << t;
        }
        else if(t <= k && t > n){
            cout << n;
        }
        else if(t > k && t > n && t <= n + k){
            cout << (k - (t - n));
        }
        else if(t > n + k){
            cout << 0;
        }
    }
    else{
        if(t <= k){
            cout << t;
        }
        else if(t > k && t <= n){
            cout << k;
        }
        else if(t > k && t > n && t <= n + k){
            cout << (k - (t - n));
        }
        else if(t > n + k){
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}

