//#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 20007
using namespace std;


int d[2][10007][145][2];
int n, t;
int a[N], s[N];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            s[i + 1] = s[i] + a[i];
        }
        for (int k = 144; k >= 1; --k) {
            int cnt = k % 2;
            for (int j = n / 2; j >= 0; --j) 
                for (int now = min(k, n - 2 * j); now >= 0; --now) {
                    int tmp = n - 2 * j - now;
                    if (tmp < k) {
                        d[cnt][j][now][0] = s[j] - (s[n] - s[n - j - now]);
                        d[cnt][j][now][1] = s[j + now] - (s[n] - s[n - j]);
                        continue;
                    }
                    d[cnt][j][now][0] = d[cnt][j + now][k - now][1];
                    d[cnt][j][now][1] = d[cnt][j + now][k - now][0];
                    if (tmp >= k + 1) {
                        d[cnt][j][now][0] = max(d[cnt][j][now][0], d[1 - cnt][j + now][k + 1 - now][1]);
                        d[cnt][j][now][1] = min(d[cnt][j][now][1], d[1 - cnt][j + now][k + 1 - now][0]);
                    }
                }
        }
        printf("%d\n", d[1][0][0][0]);
    }
    return 0;
}
