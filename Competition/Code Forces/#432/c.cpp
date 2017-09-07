/*************************************************************************
    > File Name: c.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 一  9/ 4 23:40:07 2017
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
#define eps 1e-18
using namespace std;
struct node{
    int a[5], num;
    node(){};
    node(node x, node y){
        for(int i=0; i<5; i++){
            a[i] = y.a[i] - x.a[i];
        }
    }
}p[1007];
vector<node> now;
int n;
bool cmp(node x, node y){
    return x.num < y.num;
}
int cal1(node x, node y){
    int ans = 0;
    for(int i=0; i<5; i++){
        ans += x.a[i] * y.a[i];
    }
    return ans;
}
bool ok(int i, int j, int k){
    node line1, line2;
    line1 = node(p[i], p[j]);
    line2 = node(p[i], p[k]);
    if(cal1(line1, line2) <= 0){
        return true;
    }
    return false;
}
bool check(){
    int tmp;
    if(ok(now[0].num, now[1].num, now[2].num)){
        tmp = now[0].num;
        now.clear();
        now.push_back(p[tmp]);
        return true;
    }   
    if(ok(now[1].num, now[0].num, now[2].num)){
        tmp = now[1].num;
        now.clear();
        now.push_back(p[tmp]);
        return true;
    }   
    if(ok(now[2].num, now[1].num, now[0].num)){
        tmp = now[2].num;
        now.clear();
        now.push_back(p[tmp]);
        return true;
    }
    return false;
}
bool check2(int x){
    for(int i=0; i<n; ++i){
        if(i != x){
            for(int j=i+1; j<n; ++j){
                if(j != x){
                    if(!ok(x, i, j)){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cin >> p[i].a[j];
        }
        p[i].num = i;
    }
    if(n < 3){
        if(n == 1){
            cout << 1 << "\n" << 1 << endl;
        }
        else{
            cout << 2 << endl;
            cout << 1 << endl << 2 << endl;
        }
        return 0;
    }
    else{
        now.push_back(p[0]);
        now.push_back(p[1]);
        now.push_back(p[2]);
    }
    int tot = 3;
    while(now.size() == 3){
        int nnum = 0;
        if(check()){
            while(tot < n && nnum < 2){
                now.push_back(p[tot++]);
                nnum++;
            }
        }
        else{
            now.clear();
            while(tot < n && nnum < 3){
                now.push_back(p[tot++]);
                nnum++;
            }
        }
    }
    int cnt = 2;
    vector<node> tmp;
    for(int i=0; i<now.size(); i++){
        if(check2(now[i].num)){
            tmp.push_back(now[i]);
        }
    }
    cout << tmp.size() << endl;
    if(tmp.size() != 0){
        sort(tmp.begin(), tmp.end(), cmp);
        for(int i=0; i<tmp.size(); ++i){
           cout << tmp[i].num + 1 << endl;
        }
    }
    return 0;
} 
        

