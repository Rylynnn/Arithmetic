/*************************************************************************
    > File Name: hdu1711.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 二  9/12 04:03:53 2017
 ************************************************************************/

#include <bits/stdc++.h>
#define N 1000007
#define MOD 1000000007
using namespace std;
int nxt[N];
int n, m;
int a[N], b[N];
void getnext(int *str)
{    
    int i,j;    
    int slen = m;
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
int kmp(int *s, int *str){    
    int i, j, num;
    i = j = num = 0;
    while (i < n && j < m){    
        if (j == -1||s[i] == str[j]){
            ++i,++j;
        }
        else {
            j = nxt[j];
        }
    }
    if(j == m){
        return i - j + 1;
    }
    else {
        return -1;
    }
    return num;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int ans;
    cin >> t;
	while(t--){
        ans = 0;
        memset(nxt, 0, sizeof(0));
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<m; i++){
            cin >> b[i];
        }
        getnext(b);
        ans = kmp(a, b);
        cout << ans << endl;
    }
    return 0;
}
