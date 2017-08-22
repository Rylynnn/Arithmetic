/*************************************************************************
    > File Name: A.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月18日 星期五 23时09分37秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    int m[26];
    string a;
    while(scanf("%d%d", &n, &k)!=EOF){
        cin >> a;
        int p = 0;
        memset(m, 0, sizeof(m));
        for(int i=0;i <a.size(); i++){
            m[a[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(m[i] > k){
                p = 1;
            }
        }
        if(p == 1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
