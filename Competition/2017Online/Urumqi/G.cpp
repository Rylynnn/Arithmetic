#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
const int INFS = 0x3fffffff;
const ll INFB = 0x3fffffffffffffff;
char S[100005], T[15];
int c[100005], slen, tlen;
int lowbit(int x){
    return x&(-x);
}
void add(int bit, int a){
    while(bit <= tlen + 10){
        c[bit] += a;
        bit += lowbit(bit);
    }
}
int getsum(int x){
    int sum = 0;
    while(x > 0){
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

bool cmp(int pos) {
    int i = 0;
    while(pos < tlen && i < slen) {
        if(S[i] != T[pos]) return false;
        pos++;
        i++;
    }
    return i == slen;
}

void solve() {
    for(int i = 0; i <= tlen - slen; i++) {
        if(cmp(i)) add(i + 1, 1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(c, 0, sizeof c);
        int n;
        scanf("%d %s %s", &n, T, S);
        tlen = strlen(T);
        slen = strlen(S);
        solve();
        char ch[10];
        for(int i = 0; i < n; i++) {
            scanf("%s", ch);
            if(ch[0] == 'Q') {
                int l, r;
                scanf("%d %d", &l, &r);
                if(r - l + 1 < slen) {
                    printf("0\n");
                }
                else {
                    printf("%d\n", getsum(r - slen + 1) - getsum(l - 1));
                }
            }
            else {
                int pos;
                scanf("%d %s", &pos, ch);
                pos--;
                T[pos] = ch[0];
                for(int j = max(pos - slen, 0); j <= pos; j++) {
                    int temp = getsum(j + 1) - getsum(j);
                    bool flag = cmp(j);
                    if(temp == 1 && flag == false) {
                        add(j + 1, -1);
                    }
                    else if(temp == 0 && flag == true) {
                        add(j + 1, 1);
                    }
                }
            }
        }
    }
    return 0;
}
