/*************************************************************************
    > File Name: poj2406.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/17 01:25:17 2017
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int N = 200007;
const int MOD = 10007;
typedef long long ll;
ll nxt[N];
string a;
void getnext(string str)
{    
    ll i,j;    
    ll slen = str.size();
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
int main()
{
    while(cin >> a){
        if(a == "."){
            break;
        }
        memset(nxt, 0, sizeof(nxt));
        getnext(a);
        int len = a.size();
        if(len % (len - nxt[len]) == 0){
           cout << (len / (len - nxt[len])) << endl;
        }
        else{
            cout << 1 << endl;
        }
    }
    return 0;
}
