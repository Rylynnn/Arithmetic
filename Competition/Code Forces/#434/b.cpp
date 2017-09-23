/*************************************************************************
    > File Name: b.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/17 21:26:11 2017
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    vector<int> ans;
    int k[107], f[107], a[107];
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> k[i] >> f[i];
        a[k[i]] = f[i];
    }
    if(a[n] != 0){
        cout << a[n] << endl;
    }
    int cnt = 0;
    ans.clear();
    for(int i=1; i<=100; i++){
        int p = 0;
        for(int j=0; j<m; j++){
            if(ceil((double)k[j] / (double)i) != f[j]){
                p = 1;
                break;
            }
        }
        if(p == 0){
            ans.push_back(i);
        }
    }
    int now = ceil((double)n / (double)ans[0]);
    for(int i=1; i<ans.size(); i++){
        if(ceil((double)n / (double)ans[i]) != now){
            cnt = 1;
        }
    }
    if(cnt == 1){
        cout << -1 << endl;
    }
    else{
        cout << ceil((double)n / (double)ans[0]) << endl;
    }
    return 0;
}
