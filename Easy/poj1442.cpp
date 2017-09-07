/*************************************************************************
  > File Name: poj1442.cpp
  > Author: Rylynnn
  > Mail: jingry0321@gmail.com
  > Created Time: 一  8/28 13:53:51 2017
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
#include <functional>
#define MAX 30007
using namespace std;
int m, n;
int a[MAX], u[MAX];
priority_queue<int, vector<int>, greater<int> > small;
priority_queue<int, vector<int>, less<int> > big;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        cin >> a[i];
    }
    int num = 1;
    for(int i=1; i<=n; i++){
        cin >> u[i];
        while(num <= u[i]){
            if(!big.empty() && a[num] > big.top()){
                small.push(a[num]);
            }
            else{
                big.push(a[num]);
            }
            num++;       
        }
        while(big.size() >= i){
            int now = big.top();
            big.pop();
            small.push(now);
        }
        cout << small.top() <<endl;
        big.push(small.top());
        small.pop();
    }    
    return 0;
}
