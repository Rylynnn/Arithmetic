/*************************************************************************
    > File Name: kmp.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月19日 星期六 15时05分43秒
 ************************************************************************/
#include <bits/stdc++.h>
#include <string>
#include <iostream>
#define N 1000007
#define MOD 1000000007
using namespace std;
int nxt[N];
string str, s;
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
				nxt[j] = nxt[i];
			}
			*/
		}
		else {
			i = nxt[i];
		}
	}
}
int kmp(string s,string str){	
	int i, j, num;
	i = j = num = 0;
	int n = s.size();
	int m = str.size();
	while (i < n){	
        if(j == m){
            num++;
            j = 0;
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
    int t;
	int ans;
	string a, b;
    scanf("%d", &t);
    while(t--){
        ans = 0;
        cin >> a >> b;
		getnext(b);
		ans = kmp(a, b);
        cout << ans << endl;
    }
    return 0;
}
