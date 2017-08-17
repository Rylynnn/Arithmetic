/*
ID: 15829681
LANG: C++
TASK: runround
*/
/*************************************************************************
    > File Name: 2.2.3runround.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年07月26日 星期三 02时52分10秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
ll a;
string s;
int len;
int vis[10];
string ltos(ll m){
    ostringstream os;
    os << m;
    string result;
    istringstream is(os.str());
    is >> result;
    return result;
}
ll stol(string m){
    ll result;
    istringstream is(m);
    is >> result;
    return result;
}
bool check(string b){
    int p = 0;
    for(int i=0; i<len; i++){
        if(b[i] == '0'){
            p = 1;
            break;
        }
        if(vis[b[i] - '0'] == 0){
            vis[b[i] - '0'] = 1;                
        }
        else if(vis[b[i] - '0'] == 1){
            p = 1;
            break;
        }
    }
    if(p == 0){
        return true;
    }
    else{
        return false;
    }
}
bool work(int step, int now, int loc){
    if(step == len){
        if(loc == 0){
            return true;
        }
        else{
            return false;
        }
    }
    if(vis[now] == 1){
        return false;
    }
    else if(vis[now] == 0){
        vis[now] = 1;
        loc = (now + loc) % len;
        now = s[loc % len] - '0';
        return work(step+1, now, loc);
    }
}
vector<string> ans;
int main()
{
    //freopen("runround.in", "r", stdin);
    freopen("dabiao.out", "w", stdout);
    a = 0;
    a++;
    s = ltos(a);
    ll num = 0;
    int nnow = s[0] - '0';
    len = s.size();
    memset(vis, 0, sizeof(vis));
    while(1){
        while(1){
            s = ltos(a);
            len = s.length();
            memset(vis, 0, sizeof(vis));
            if(check(s) == true){
                break;
            }
            a++;
        }
        nnow = s[0] - '0';
        memset(vis, 0, sizeof(vis));
        if(work(0, nnow, 0) == true){
            ans.push_back(s);
            cout << s << ',';
            num++;   
            if(num % 10 == 0){
                cout << endl;
            }
        }
        if(s == "9682415"){
            break;
        }
        a++;
    }
 //   cin >> a;
 //   vector<string>::iterator it;
 //   for(it=ans.begin(); it!=ans.end(); ++it){
 //       if(stol(*it) > a){
 //           cout << *it << endl;
 //           break;
 //       }
 //   }
 //   cout << num << endl;
}
