#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <list>
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)
#define h(x, y, z) for(int x = (y); x >= (z); --x)
#define foreach(x, y) for(__typeof(y.begin()) x = y.begin(); x != y.end(); ++x)
typedef long long LL;
typedef std::pair<int, int> PII;
typedef long double real;
 
using std::vector;
using std::lower_bound;
 
struct point{
    real k; LL x, y;
    inline point(real _k = 0, LL _x = 0, LL _y = 0) :k(_k), x(_x), y(_y){}
};
inline bool operator <(point a, point b){
    return a.k < b.k;
}
 
//Persistent Convex Hull 233
struct PCH{
    int n;
    point *curr, *hist, *hiend;
    int *hn, *hend;
    inline PCH(int size){
        n = 0;
        curr = (point *) malloc(sizeof(point) * (size + 2));
        hiend = hist = (point *) malloc(sizeof(point) * (size + 2));
        hend = hn = (int *) malloc(sizeof(int) * (size + 2));
    }
    inline void push(point a){
        point *pos;
        if(n == 0){
            a.k = 0x8080808080808080LL;
            *(hiend++) = *curr; *(hend++) = 0;
            *curr = a; n = 1;
        }else{
            int l = 0, r = n - 1;
            while(l < r){
                int cans = (l + r) >> 1;
                a.k = (real) (a.y - curr[cans].y) / (a.x - curr[cans].x);
                if(cans == n - 1 || a < curr[cans + 1]) r = cans; else l = cans + 1;
            }
            a.k = (real) (a.y - curr[l].y) / (a.x - curr[l].x);
            pos = curr + (l + 1);
            *(hiend++) = *pos; *(hend++) = n;
            *pos = a; n = l + 2;
        }
    }
    inline void pop(){
        curr[n - 1] = *(--hiend);
        n = *(--hend);
    }
    inline LL query(LL k){
        point a = k;
        point *pos = lower_bound(curr, curr + n, a);
        if(pos != curr) --pos;
        return pos->y - pos->x * k;
    }
};
 
struct node{
    node *ls, *rs;
    int l, r, m;
    PCH *data;
    inline node(int ll, int rr) :l(ll), r(rr), m((ll + rr) >> 1){
        if(l == r){
            ls = rs = NULL;
            data = new PCH(1);
        }else{
            ls = new node(l, m); rs = new node(m + 1, r);
            data = new PCH(r - l + 1);
        }
    }
    inline void push(int x, point y){
        data->push(y);
        if(l != r){
            if(x <= m) ls->push(x, y);
            else rs->push(x, y);
        }
    }
    inline void pop(int x){
        data->pop();
        if(l != r){
            if(x <= m) ls->pop(x);
            else rs->pop(x);
        }
    }
    inline LL query(int ll, int rr, LL k){
        if(ll > rr) return 0x1f1f1f1f1f1f1f1fLL;
        if(l == ll && r == rr) return data->query(k);
        else if(rr <= m) return ls->query(ll, rr, k);
        else if(ll > m) return rs->query(ll, rr, k);
        else return std::min(ls->query(ll, m, k), rs->query(m + 1, rr, k));
    }
};
 
vector<int> sons[200086];
int fa[200086]; LL pd[200086], p[200086], q[200086], l[200086], dp[200086], ddp[200086];
 
node *root;
 
inline void dfs(int i, LL dist, int dep){
    ddp[dep] = (dist += pd[i]);
    int ll = lower_bound(ddp, ddp + dep, dist - l[i]) - ddp;
    dp[i] = root->query(ll, dep - 1, p[i]) + q[i] + p[i] * dist;
    root->push(dep, point(0, dist, dp[i]));
    foreach(son, sons[i]) dfs(*son, dist, dep + 1);
    root->pop(dep);
}
 
int main(){
    int n; scanf("%d%*d", &n);
    f(i, 2, n){
        scanf("%d%lld%lld%lld%lld", fa + i, pd + i, p + i, q + i, l + i);
        sons[fa[i]].push_back(i);
    }
    root = new node(0, n - 1);
    dp[0] = 0; ddp[0] = 0;
    root->push(0, point());
    foreach(son, sons[1]) dfs(*son, 0, 1);
    f(i, 2, n) printf("%lld\n", dp[i]);
    return 0;
}
