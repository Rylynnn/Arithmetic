/*************************************************************************
    > File Name: d.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 三  9/ 6 22:20:53 2017
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
int n, m, k;
struct node{
    int d, f, t, c;
}a[100007], b[100007];
bool cmp1(node q, node p){
    if(q.f != p.f){
        return q.f < p.f;
    }
    else{
        return q.d < p.d;
    }
}
bool cmp2(node q, node p){
    if(q.t != p.t){
        return q.t < p.t;
    }
    else{
        return q.d < p.d;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    int num = 0, cnt1 = 0, cnt2 = 0;
    for(int i=0; i<m; i++){
        node now;
        cin >> now.d >> now.f >> now.t >> now.c;
        if(now.t == 0){
            a[cnt1++] = now;
        }
        else{
            b[cnt2++] = now;
        }
    }
    sort(a, a+cnt1, cmp1);
    sort(b, b+cnt2, cmp2);
    for(int i=0; i<cnt1; ++i){
        cout << a[i].d << a[i].f << a[i].t << a[i].c << endl;
    }
    for(int i=0; i<cnt2; ++i){
        cout << b[i].d << b[i].f << b[i].t << b[i].c << endl;
    }
    int be = 0, ar = 0;
    while(be != cnt1 && ar != cnt2){
        break;
    }
    return 0;
}  
