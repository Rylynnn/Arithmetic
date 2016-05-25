#include <bits/stdc++.h>
using namespace std;
int color[100007];
int main() {
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF) {
        int a, b, c;
        memset(color, 0, sizeof(color));
        for(int i = 1; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            if(color[a] != 0) {
                color[b] = color[a] + 1;
                color[c] = color[a] + 2;
                if(color[b] > 3)
                    color[b] -= 3;
                if(color[c] > 3)
                    color[c] -= 3;
            }
            else if(color[b] != 0) {
                color[a] = color[b] + 2;
                color[c] = color[b] + 1;
                if(color[a] > 3)
                    color[a] -= 3;
                if(color[c] > 3)
                    color[c] -= 3;
            }
            else if(color[c] != 0) {
                color[a] = color[c] + 1;
                color[b] = color[c] + 2;
                if(color[a] > 3)
                    color[a] -= 3;
                if(color[b] > 3)
                    color[b] -= 3;
            }
            else{
                color[a] = 1;
                color[b] = 2;
                color[c] = 3;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i == 1)
                printf("%d", color[i]);
            else
                printf(" %d", color[i]);
        }
        printf("\n");
    }
    return 0;
}
