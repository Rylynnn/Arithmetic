/*************************************************************************
    > File Name: bzoj3488.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月11日 星期五 16时21分11秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 
using namespace std;
struct node{
    int l, r, num;
}seg[4 * N];
int n, m, q, vis[N], dfs_num[4 * N], fir[N], st[4 * N][20];
struct Tree{
    vector<int> son;
    int fa;
}num[N];
void add(int u, int v){
    num[u].son.push_back(v);
    num[v].fa = u;
}
int tmp = 1;
void dfs(int x){
    dfs_num[tmp++] = x;
    fir[x] = tmp - 1;
    if(num[x].son.size() == 0){
        return;
    }
    for(int i=0; i<num[x].son.size(); i++){
        dfs(num[x].son[i]);
        dfs_num[tmp++] = x;
    }
}
void get_st(){
    for(int i=1; i<tmp; i++){
        st[i][0] = dfs_num[i];
    }
    for(int j=1; (1<<j)<tmp; j++){
        for(int i=1; i<tmp-(1<<j)+1; i++){
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1];
        }
    }
}
int find(int u, int v){
    if(u > v){
        swap(u, v);
    }
    while((1<<j) <= (y-x+1)){
        j++;
    }
    j--;
    return min(st[x][j], st[y-(1<<j)+1][j]);
}
void merge(int a, int b){
    if(a.l == NULL){
        a.l = b.l;
    }
    else if(b.l != NULL){
        merge(a.l, b.l);
    }
    if(a.r == NULL){
        
int main()
{
    int a, b;
    scanf("%d", &n);
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++){
        scanf("%d%d", &a, &b);
        add(a, b);
        vis[b] = 1;
    }
    for(int i=1; i<=n ;i++){
        if(vis[i] == 0){
            sta = i;
            break;
        }
    }
    dfs(sta);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    scanf("%d", &q);
    for(int i=0; i<q; i++){
        scanf("%d%d", &a, &b);
        find(fir[a], fir[b]);
    }
    return 0;
}
