#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
ll g;
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

ll ans;
void bfs(ll x, ll y) {
    while(y % (x + 1) == 0){
        ans++;
        y = y / (x + 1);
        if(x > y){
            swap(x, y);
        }
    }
    return;
}

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    ll x, y;
    while(kase < T) {
        scanf("%I64d%I64d", &x, &y);
        if(x>y){
            swap(x,y);
        }
        g=gcd(x,y);
        x/=g;
        y/=g;
        ans = 1;
        bfs(x, y);
        printf("Case #%d: %I64d\n", ++kase, ans);
    }
    return 0;
}
