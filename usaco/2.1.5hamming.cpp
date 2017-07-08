/*
ID:15829681
LANG:C++
TASK:hamming
*/
#include <cstdio>
#include <cstring>
#include <bitset>
#include <iostream>
#include <fstream>
using namespace std;
bitset<10> k[259], m;
int ans[71];
int n,b,d;
void init(){
    for(int i=0;i<256;i++){
        int now = i;
        int tmp = 0;
        while(now){
            if(now & 1){
                k[i][tmp] = 1;
            }
            else{
                k[i][tmp] = 0;
            }
            now = now >> 1;
            tmp++;
        }
        //cout << k[i] << ' ';
    }
    return;
}
void dfs(int num, int now){
    if(num == n || now > 255){
        return;
    }
    for (int i=now+1;i<255;i++){
        int p = 0;
        for (int j=0;j<num;j++){
            m = k[i] ^ k[ans[j]];
            if(m.count() < d){
                p = 1;
            }
        }
        if(p == 0){
            ans[num] = i;
            if(num % 10 == 0){
                cout << '\n' << i;
            }
            else{
                cout << ' ' << i;
            }
            dfs(num+1, i);
            break;
        }
    }
    return;
}
int main()
{
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);
    init();
    scanf("%d%d%d", &n, &b, &d);
    cout << "0";
    ans[0] = 0;
    dfs(1, 0);
    cout << endl;
}
