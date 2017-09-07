/*************************************************************************
    > File Name: cc.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 二  9/ 5 00:34:43 2017
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
bool cmp(node x, node y){
	return x.num < y.num;
}
int vis[1007];
double cal1(node x, node y){
    double ans = 0;
    for(int i=0; i<5; i++){
        ans += x.a[i] * y.a[i];
    }
    return ans;
}
double cal2(node x, node y){
    double ans = cal1(x, y) / (sqrt(cal1(x, x)) * sqrt(cal1(y, y)));
    return ans;
}
bool ok(int i, int j, int k){
    node line1, line2;
    line1 = node(p[i], p[j]);
    line2 = node(p[i], p[k]);
    if(cal2(line1, line2) > eps){
        return true;
    }
    return false;
}
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
	memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cin >> p[i].a[j];
        }
		p[i].num = i;
    }
    if(n > 243){
        cout << 0;
        return 0;
    }
	int cnt = n;
    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i == j){
				continue;
			}
			int p = 0;
			for(int k=0; k<n; k++){
				if(j == k|| i == k){	
					continue;
				}
				if(ok(i, j, k)){
					p = 1;
					vis[i] = 1;
					cnt--;
					break;
				}
			}
			if(p == 1){
				break;
			}
		}
	}
	cout << cnt << endl;
	for(int i=0; i<n; i++){
		if(!vis[i])
			cout << i+1 << endl;
	}
	return 0;
}
