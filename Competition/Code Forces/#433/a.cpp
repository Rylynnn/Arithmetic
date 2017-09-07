/*************************************************************************
    > File Name: a.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 三  9/ 6 20:46:08 2017
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
int gcd(int a, int b){
    return (b == 0) ? a :gcd(b, a%b);
}
double ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, aa, bb;
    cin >> n;
    ans = 0;
    for(int i=1; 2*i<n; i++){
        if(gcd(i, n-i) == 1){
            if((double)i/(n-i) > ans){
                aa = i;
                bb = n-i;
                ans = (double)i / (n-i);
            }
        }
    }
    cout << aa << ' ' << bb;
    return 0;
}
