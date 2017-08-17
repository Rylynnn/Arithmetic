/*************************************************************************
    > File Name: K.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月01日 星期二 22时34分46秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#define N 100007
using namespace std;
struct node{//链式前向星存树边
    int next;
    int to;
    int w;
}edge[N * 2];
int head[N], cnt, n;
int fa[25][N];
int dep[N], cost[N];
void add(int u, int v, int w){
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u, int f, int d){
    int now;
    dep[u] = d;
    fa[0][u] = f;
    for(int i=head[u]; ~i; i=edge[i].next){
        now = edge[i].to;
        if(now == f){
            continue;
        }
        cost[now] = cost[u] + edge[now].w;
        dfs(now, u, d+1);
    }
    return;
} 

void bz(){
    for(int i=0; i+1<25; i++){
        for(int j=1; j<=n; j++){
            if(fa[i][j] == 0){
                fa[i+1][j] = 0;
            }
            else{
                fa[i+1][j] = fa[i][fa[i][j]];
            }
        }
    }
}

int lca(int u, int v){
    if(dep[u] > dep[v]){//写反了- -
        swap(u, v);
    }
    for(int i=0; i<25; i++){
        if(((dep[v] - dep[u]) >> i) & 1 == 1){
            v = fa[i][v];
        }
    }
    if(u == v){ 
        return u;
    }
    for(int i=24; i>=0; i--){//24写成了25...- -
        if(fa[i][u] != fa[i][v]){
            u = fa[i][u];
            v = fa[i][v];
        }
    }
    return fa[0][u];
}
int main(){
    int t, u, v, k;
    string obey;
    cin >> t;
    while(t--){
        memset(head, -1, sizeof(head));
        memset(fa, 0, sizeof(fa));
        cnt = 0;
        cin >> n;
        for(int i=1; i<n; i++){
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
            add(b, a, c);
        }
        dfs(1, 0, 0);
        bz();
        while(cin >> obey){
            if(obey == "DONE"){
                break;
            }
            else if(obey == "DIST"){
                cin >> u >> v;
                int ans = lca(u, v);
                cout << cost[v] + cost[u] - 2 * cost[ans] << endl;
            }
            else if(obey == "KTH"){
                cin >> u >> v >> k;
                int ans = lca(u, v);
                if(dep[u] - dep[ans] < k){
                    k = dep[ans] + (k - (dep[u] - dep[ans] + 1));
                    u = v;
                    for(int i=0; i<25; i++){//都写成了25..哇..服了我自己了emmm
                        if(d){
                            u = fa[i][u];
                        }
                    }
                    cout << u << endl;
                }
                else{
                    int num = dep[u] - k + 1;
                    for(int i=24; i>=0; i--){
                        if(dep[u] - (1 << i) >= num){
                            u = fa[i][u];
                        }
                    }
                    cout << u << endl;
                }
            }
        }
    }
    return 0;
}

