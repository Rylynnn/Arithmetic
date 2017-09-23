/*************************************************************************
    > File Name: hdu2087.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 三  9/13 01:38:30 2017
 ************************************************************************/
#include <bits/stdc++.h>
#define N 1000007
#define MOD 1000000007
using namespace std;
int nxt[N], ans;
void getnext(string str)
{    
    int i,j;    
    int slen = str.size();
    i=-1,j=0;
    nxt[0] = -1;
    while (j < slen){
        if (i == -1||str[i] == str[j]){    
            ++i,++j;
            if (str[i] != str[j]){
                nxt[j] = i;
            }
            else {
                nxt[j] = nxt[i];
            }
        }
        else {
            i = nxt[i];
        }
    }
}
int kmp(string s, string str){    
    int i, j, num;
    int n = s.size();
    int m = str.size();
    i = j = num = 0;
    while (i < n){
        if (j == m){
            j = 0;
            num++;
        }    
        if (j == -1||s[i] == str[j]){
            ++i,++j;
        }
        else {
            j = nxt[j];
        }
    }
    if(j == m){
        num++;
    }
    return num;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	string a, b;
    while(cin >> a){
        if(a == "#"){
            break;
        }
        cin >> b;
        ans = 0;
        memset(nxt, 0, sizeof(0));
        getnext(b);
        /*for(int i=0; i<b.size(); ++i){
            cout << nxt[i] << ' ';
        }*/
        ans = kmp(a, b);
        cout << ans << endl;
        a.clear();
        b.clear();
    }
    return 0;
}
