/*************************************************************************
    > File Name: poj1088.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月06日 星期日 16时33分41秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int r, c, ans;
int m[107][107], dp[107][107], vis[107][107];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dfs(int x, int y){
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx > 0 && nx <= c && ny > 0 && ny <= r){
            if(m[nx][ny] > m[x][y]){
                int now = dfs(nx, ny);
                if(dp[x][y] < now + 1){
                    dp[x][y] = now + 1;
                }
            }
        }
    }
    return dp[x][y];
}
int main()
{
    while(scanf("%d%d", &r, &c)!=EOF){
        memset(m, 0, sizeof(m));
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                scanf("%d", &m[i][j]);
            }
        }
        int maxm = 0;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                maxm = max(maxm, dfs(i, j));
            }
        }
        printf("%d", maxm + 1);
    }
    return 0;
}
