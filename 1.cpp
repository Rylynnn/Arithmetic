#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}
int maxm, sum;
int n, a[57], vis[57];
void dfs(int x, int num){
    if(num == n){
        maxm = max(maxm, sum);
        return;
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = 1;
            sum += abs(a[x] - a[i]);
            dfs(i, num+1);
            vis[i] = 0;
            sum -= abs(a[x] - a[i]);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n, cmp);
    maxm = 0;
    for(int i=0; i<n; i++){
        memset(vis, 0, sizeof(vis));
        vis[i] = 1;
        sum = 0;
        dfs(i, 1);
    } 
    printf("%d", maxm);
    return 0;
}
