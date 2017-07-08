/*
ID:15829681
LANG:C++
TASK:holstein
 */
/*************************************************************************
    > File Name: 2.1.4holstein.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: Thu 29 Jun 2017 03:02:00 AM CST
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <bitset>
#define INF 0x3f3f3f3f
using namespace std;
int flag;
int ans[29], vis[29], now[29];
int v, g;
int a[29], b[29][29];
bool check(){
    for(int i=0;i<v;i++){
        if(a[i] > now[i]){
            return false;
        }
    }
    return true;
}
void dfs(int num, int aim)
{
    if(num < flag && check() == true){
        flag = num;
        for(int i=0;i<g;i++){
            ans[i] = vis[i];
        }
        return;
    }
    for(int i=aim;i<g;i++){
        if(!vis[i]){
            for(int j=0;j<v;j++){
                now[j] += b[i][j];
            }
            vis[i] = 1;
            dfs(num+1, i+1);
            for(int j=0;j<v;j++){
                now[j] -= b[i][j];
            }
            vis[i] = 0;
        }
    }
    return;
}
int main()
{
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    scanf("%d", &v);
    for (int i=0;i<v;i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &g);
    for(int i=0;i<g;i++){
        for(int j=0;j<v;j++){
            scanf("%d", &b[i][j]);
        }
    }
    flag = INF;
    for(int i=0;i<g;i++){
        memset(vis, 0, sizeof(vis));
        memset(now, 0, sizeof(now));
        dfs(0,i);
    }
    printf("%d", flag);
    for(int i=0;i<g;i++){
        if(ans[i] == 1){
            printf(" %d",i+1);
        }
    }
    printf("\n");
    return 0;
}
