/*************************************************************************
    > File Name: poj2752.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/17 01:52:33 2017
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int N = 400007;
const int MOD = 10007;
typedef long long ll;
int nxt[N];
string a;
void getnext(string str)
{    
    int i,j;    
    int slen = str.size();
    i=-1,j=0;
    nxt[0] = -1;
    while (j < slen){
        if (i == -1||str[i] == str[j]){    
            ++i,++j;
            nxt[j] = i;
            /*
            加速优化匹配的nxt数组，原nxt数组为前缀与后缀相同的最长子串长度，优化后为有可能可以重新匹配的下一个位置
            if (str[i] != str[j]){
                nxt[j] = i;
            }
            else {
                j = nxt[i];
            }
            */
        }
        else {
            i = nxt[i];
        }
    }
}
int main(){
    int ans[N];
    while(cin >> a){
        memset(ans, 0, sizeof(ans));
        memset(nxt, 0, sizeof(nxt));
        getnext(a);
        int cnt = 0;
        int tmp = a.size();
        while(nxt[tmp]!=0){
            ans[cnt++] = nxt[tmp];
            tmp = nxt[tmp];
        }
        if(cnt != 0){
            cout << ans[cnt-1];
        }
        for(int i=cnt-2; i>=0; --i){
            cout << ' ' << ans[i];
        } 
        if(cnt != 0){
            cout << ' ' << a.size() << endl;
        }
        else{ 
            cout << a.size() << endl;
        }
    }
    return 0;
}
