/*************************************************************************
    > File Name: hdu2068.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月10日 星期四 15时10分32秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string t;
char st[220009];
int p[220009], n;
void init(){
    st[1] = '#';
    for(int i=1; i<=n; i++){
        st[i*2+1] = '#';
        st[i*2] = t[i-1];
    }
    n = n * 2 + 1;
    st[0] = '%', st[n+1] = '$';
}
int manacher(){
    int id, ans = 0;
    p[1] = 0, id = 1;
    for(int i=2; i<=n; i++){
        if(i <= id + p[id]){
            p[i] = min(p[2*id - i], id + p[id] - i);
        }
        else{
            p[i] = 1;
        }
        while(st[i - p[i]] == st[i + p[i]]){
            ++p[i];
        }
        --p[i];
        if(i + p[i] > id + p[id]){
            id = i;
        }
        ans = max(ans, p[i]);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);//tle变ac关键
    while(cin >> t){
        memset(p, 0, sizeof(p));
        memset(st, -1, sizeof(st));
        n = t.size();
        init();
        cout << manacher() << endl;
    }
    return 0;
}
