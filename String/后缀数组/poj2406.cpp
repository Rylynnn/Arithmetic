/*************************************************************************
    > File Name: poj2406.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月10日 星期四 21时23分11秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#define MAXN
using namespace std;
string s;
int sa[MAXN];
int t1[MAXN], t2[MAXN], c[MAXN];
int ran[MAXN], height[MAXN];
void build_sa(int s[], int n, int m){
    int i, j, p, *x=t1, *y=t2;
    for(i=0; i<m; i++)c[i] = 0;
    for(i=0; i<n; i++)c[x[i] = s[i]]++;
    for(i=1; i<m; i++)c[i] += c[i-1];
    for(i=n-1; i>=0; i--)sa[--c[x[i]]] = i;
    for(j=1; j<=n; j<<=1){
        p = 0;
        for(i=n-j; i<n; i++)y[p++] = i;
        for(i=0; i<n; i++)if(sa[i]>=j)y[p++] = sa[i] - j;
        for(i=0; i<m; i++)c[i] = 0;
        for(i=0; i<n; i++)c[x[y[i]]]++;
        for(i=1; i<m; i++)c[i] += c[i-1];
        for(i=n-1; i>=0; i--)sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1;x[sa[0]] = 0;
        for(i=1; i<n; i++)
            x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1]+j] == y[sa[i]+j]?p-1:p++;
        if(p >= n)break;
        m = p;
    }
}
void get_height(int s[], int n){
    int i, j, k = 0;
    for(i=0; i<=n; i++)ran[sa[i]] = i;
    for(i=0; i<n; i++){
        if(k)k--;
        j = sa[ran[i] - 1];
        while(s[i+k] == s[j+k])k++;
        height[ran[i]] = k;
    }
}
int main()
{
    while(cin >> s){
        if(s == "."){
            break;
        }

    }
    return 0;
}
