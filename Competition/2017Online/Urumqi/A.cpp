/*************************************************************************
    > File Name: A.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 六  9/ 9 12:14:11 2017
 ************************************************************************/

//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
#define N 51
using namespace std;
int vis[N][N];
vector<int> ban[N], mon[N];
vector<pair<int, int> > ans;
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t, n, m, a, b;
    scanf("%d", &t);
    while(t--){
        int len1, len2;
        scanf("%d%d", &n, &m);
        ans.clear();
        for(int i=0; i<=50; i++){mon[i].clear();}
        for(int i=0; i<=50; i++){ban[i].clear();}
        for(int i=0; i<=50; i++){
            for(int j=0; j<=50; j++){
                vis[i][j] = 0;
            }
        }
        for(int i=0; i<n; i++){
            scanf("%d%d", &a, &b);
            mon[a].push_back(b);
        }
        for(int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            ban[a].push_back(b);
        }
        for(int i=1; i<=50; i++){
            len1 = mon[i].size();
            for(int j=0; j<len1; j++){
                len2 = ban[mon[i][j]].size();
                for(int k=0; k<len2; k++){
                    if(!vis[i][ban[mon[i][j]][k]]){
                        vis[i][ban[mon[i][j]][k]] = 1;
                        ans.push_back(make_pair(i, ban[mon[i][j]][k]));
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        len1 = ans.size();
        for(int i=0; i<len1; i++){
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
        printf("\n");
    }
    return 0;
}
