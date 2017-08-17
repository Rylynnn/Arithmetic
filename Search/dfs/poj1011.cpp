/*************************************************************************
    > File Name: poj1011.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月03日 星期四 17时42分37秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[77], vis[77], n_len;
bool cmp(int m, int n){
    return m > n;
}
bool dfs(int len, int now, int num){
    if(num == n){
        return true;
    }
    for(int i=now; i<n; i++){
        if(!vis[i]){
            if(!vis[i-1] && a[i] == a[i-1]){
                continue;
            }

            if(len - a[i] > 0){
                vis[i] = 1;
                if(dfs(len-a[i], i, num+1)){
                    return true;
                }
                vis[i] = 0;
            }
            else if(len - a[i] == 0){
                vis[i] = 1;
                if(dfs(n_len, 0, num+1)){
                    return true;
                }
                vis[i] = 0;
            }
            if(len == n_len){
                return false;
            }
        }
    }
    return false;
}

int main()
{
    while(scanf("%d", &n)!=EOF){
        if(n == 0){
            break;
        }
        int sum = 0;
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a+n, cmp);
        for(int i=1; i<=sum; i++){
            if(sum % i == 0 && i >= a[0]){
                memset(vis, 0, sizeof(vis));
                n_len = i;
                if(dfs(i, 0, 0)){
                    cout << i << endl;
                    break;
                }
            }
        }
    } 
    return 0;
}

