/*************************************************************************
    > File Name: I.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月01日 星期二 21时15分53秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[4007], b[4007], c[4007], d[4007];
int ab[20000007], cd[20000007];
bool cmp(int p, int q){
    return p < q;
}
int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    int tmp = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ab[tmp++] = a[i] + b[j];
        }
    }
    tmp = 0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cd[tmp++] = c[i] + d[j];
        }
    }
    int len = n * n;
    int now, ans = 0;
    sort(ab, ab + len, cmp);
    sort(cd, cd + len, cmp);
    for(int i=0; i<len; i++){
        now = 0 - ab[i];
        int p = lower_bound(cd, cd + len, now) - cd;
        for(int j=p; j<len; j++){
            if(cd[j] == now){
                ans++;
            }
            if(cd[j] != now){
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
