/*************************************************************************
    > File Name: C.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月01日 星期二 16时30分43秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
string s;
queue<char> u;
stack<char> t;
int p[26], m[100007], ps, pt;
int main(){
    cin >> s;
    memset(m, 0,sizeof(m));
    m[s.size() - 1] = s[s.size() - 1] - 'a';
    for(int i=s.size() - 2; i>=0; i--){
        m[i] = min(m[i+1], s[i] - 'a');
    }
    for(int i=0; i<s.size(); i++){
        while(!t.empty() && t.top() - 'a' <= m[i]){
            u.push(t.top());
            t.pop();
        }
        t.push(s[i]);
    }
    while(!t.empty()){
        u.push(t.top());
        t.pop();
    }
    while(!u.empty()){
        cout << u.front();
        u.pop();
    }
    cout << endl;
    return 0;
}

