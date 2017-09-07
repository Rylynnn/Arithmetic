/*************************************************************************
    > File Name: a.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  8/27 20:01:23 2017
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
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
#define ll long long
#define MAXN 507
using namespace std;
const ll MOD1 = 1e12 + 7, MOD2 = 191919191919;
string s[MAXN];
map<ll, pair<int, int> > mp;
int n, m, ansk = 0;
ll poi[MAXN], now[MAXN];
ll h[MAXN][MAXN], row[MAXN], len;
void init_row(int n){
    len = n;
    row[0] = 1;
    for(int i=1; i<=len; i++){
		row[i] = row[i-1] * MOD1;
	}
}
void init_col(int id, const string &str){
    h[id][len] = 0;
    for(int i = len - 1; i >= 0; i--){
        h[id][i] = h[id][i+1] * MOD1 + (str[i] - 'a' + 1);
    }
}
ll get_hash(int id, int st, int num){
    return h[id][st] - h[id][st + num] * row[num];
}
void init_now(int len)
{
    now[0] = 1;
    for(int i = 1; i<=len; i++){
		now[i] = now[i-1] * MOD2;
	}
}
void get_poi(int j, int x){
	for(int i=1; i<=n; i++){
		poi[i] = poi[i-1] * MOD2 + get_hash(i, j, x);
    }
}
bool check_num(int x)
{
    mp.clear();
    ll tmp;
    for(int j=0; j+x-1<m; j++){
        poi[0] = 0;
      	get_poi(j, x);
        for(int k=x; k<=n; k++){
            tmp = poi[k] - poi[k - x] * now[x];
            if(mp.find(tmp) != mp.end()){
                return true;
            }
            else{
                mp[tmp] = pair<int, int>(k - x + 1, j + 1);
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false); 
	cin.tie(0);
    while(cin >> n >> m){
	    init_row(m);
	    for(int i = 1; i <= n; i++){
	        cin >> s[i];
	        init_col(i, s[i]);
	    }
	    init_now(n);
	    int l = 0, r = min(n, m) + 1, mid;
	    while(l + 1 < r){
	        mid = (l + r) >> 1;
	        if(check_num(mid)){
	            ansk = mid; l = mid;
	        }
	        else r = mid;
	    }
		cout << ansk << "\n";
	}
	return 0;
}
