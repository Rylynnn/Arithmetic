/*************************************************************************
    > File Name: b.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 一  9/ 4 22:57:47 2017
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
#define ll long long
#define eps 1e-18
using namespace std;
struct node{
    ll x, y;
}a, b, c;
ll len[4];
ll cal(node p, node q){
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}
bool gongxian(node a, node b, node c){
    if((c.y - b.y) * (b.x - a.x) - (b.y - a.y) * (c.x - b.x) == 0){
        return false;
    }
    else{
        return true;
    }
}
bool check(node q, node w, node e){
    len[1] = cal(q, w);
    len[3] = cal(w, e);
    len[2] = cal(q, e);
    if(len[1] - len[3] == 0 && gongxian(q, w, e)){
            return true;
    }
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    if(check(a, b, c)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }  
    return 0;
} 
