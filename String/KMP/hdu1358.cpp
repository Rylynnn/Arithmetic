/*************************************************************************
    > File Name: hdu1358.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 三  9/13 00:08:13 2017
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int N = 1000007;
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int kase = 0;
    while(cin >> n) {
        kase++;
        if(n == 0){
            break;
        }
        cin >> a;
        memset(nxt, 0, sizeof(nxt));
        getnext(a);
        cout << "Test case #" << kase << endl;
        for(int i=1; i<=n; i++){
            if(nxt[i] != 0 && (i % (i - nxt[i]) == 0)){
                cout << i << ' ' << i / (i - nxt[i]) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}

