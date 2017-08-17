/*************************************************************************
    > File Name: hdu5724.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月06日 星期日 16时04分59秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 20000007
using namespace std;
int sg[N];
int dfs(int x){
    if(sg[x] != -1){
        return sg[x];
    }
    int vis[40];
    memset(vis, 0, sizeof(vis));
    for(int i=19; i>=0; i--){
        if((x & (1 << i))){
            for(int j=i-1; j>=0; j--){
                if(!(x & (1 << j))){
                    int nx = x - (1 << i) + (1 << j);
                    vis[dfs(nx)] = 1;
                    break;
                }
            }
        }
    }
    for(int i=0; i<=21;i++){
        if(vis[i] == 0){
            sg[x] = i;
            break;
        }
    }
    return sg[x];
}
int main()
{
    int t, n, m, ans, a;
    memset(sg, -1, sizeof(sg));

    for(int i=0; i<(1 << 20); i++){
        dfs(i);
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = 0;
        for(int i=0; i<n; i++){
            scanf("%d", &m);
            int now = 0;
            for(int j=0; j<m; j++){
                scanf("%d", &a);
                now += 1 << (20 - a);
            }
            ans = ans ^ sg[now];
        }
        if(ans == 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}
