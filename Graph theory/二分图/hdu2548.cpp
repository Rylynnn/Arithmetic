/*************************************************************************
    > File Name: hdu2548.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月04日 星期五 16时13分18秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int gra[207][207], ma[207][207];
int vis[207], linker[207];
int g, b, m, cnt;
bool dfs(int u){
    for(int v=1; v<=b; v++){
        if(!gra[u][v] && !vis[v]){
            vis[v] = 1;
            if(linker[v] == -1 || dfs(linker[v])){
                linker[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int x, y, kase = 0;
    while(scanf("%d%d%d", &g, &b, &m) != EOF){
        if(g == 0 && b == 0 && m == 0){
            break;
        }
        memset(gra, 0, sizeof(gra));
        memset(ma, 0, sizeof(ma));
        for(int i=0; i<m; i++){
            scanf("%d%d", &x, &y);
            gra[x][y] = 1;
        }
        cnt = 0;
        memset(linker, -1, sizeof(linker));
        for(int i=1; i<=g; i++){
            memset(vis, 0, sizeof(vis));
            if(dfs(i)){
                cnt++;
            }
        }
        cout << "Case " << ++kase << ": " << (g + b) - cnt << endl;
    }
    return 0;
}
