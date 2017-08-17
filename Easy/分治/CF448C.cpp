/*************************************************************************
    > File Name: B.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月02日 星期三 13时58分00秒
 ************************************************************************/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[5009];
int dfs(int l, int r){
    if(l > r || l < 0 || r >= n){
        return 0;
    }
    int minm = INF, sum = 0, ans;
    for(int i=l; i<=r; i++){
        if(a[i] < minm){
            minm = a[i];
        }
        sum++;
    }
    for(int i=l; i<=r; i++){
        a[i] -= minm;
    }
    ans = minm;
    for(int i=l; i<=r; i++){
        if(a[i] != 0){
            int be = i;
            while(be <= r && a[be] != 0){
                be++;
            }
            ans += dfs(i, be - 1);
            i = be;
        }
    }
    return min(sum, ans);
}  
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    cout << dfs(0, n-1) << endl;
}
