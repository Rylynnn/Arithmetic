/*************************************************************************
    > File Name: c.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/17 23:04:25 2017
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
string a;
bool check(int i){
    if(a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u'){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int vis[27];
    memset(vis, 0, sizeof(vis));
    cin >> a;
    int num = 0;
    for(int i=0; i<a.size();){
        
    }
    return 0;
}
