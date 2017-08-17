#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <string>
#define make make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef map<int, int> mii;

const int maxn = 10010;
const int maxm = 1000010;
const int maxs = 26;
const int inf = 0x3f3f3f3f;
const int P = 1000000007;
const double eps = 1e-6;

inline ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9')
		  f = (ch == '-' ? -1 : 1), ch = getchar();
	while (ch >= '0' && ch <= '9')
	 	  x = x * 10 + ch - '0', ch = getchar();
	return x * f;
}

struct Heap
{
	pii val; int dis; Heap *ls, *rs;
} *null, *H[maxn], *h[maxn];

void init()
{
	null = new Heap();
	null -> val = make(inf, 0);
	null -> dis = -1;
	null -> ls = null -> rs = null;
}

Heap *marge(Heap *a, Heap *b)
{
	if (a == null) return b;
	if (b == null) return a;
	
	if (a -> val > b -> val) swap(a, b);
	Heap *c = new Heap(); *c = *a;
	
	c -> rs = marge(a -> rs, b);
	if (c -> rs -> dis > c -> ls -> dis)
		swap(c -> ls, c -> rs);
	c -> dis = c -> rs -> dis + 1;
	
	return c;
}

Heap *join(Heap *a, pii b)
{
	Heap *c = new Heap();
	c -> val = b, c -> dis = 0;
	c -> ls = c -> rs = null;
	return marge(a, c);
}

struct edge
{
	int v, w, next;
} e[maxm], _e[maxm], Te[maxn];

int n, m, cnt, ans, S, T, K, head[maxn], dis[maxn], 
	vis[maxn], _u[maxm], _cnt, _head[maxn], Tcnt, 
	Thead[maxn], fa[maxn], delta[maxm];

void insert(int u, int v, int w)
{
	e[cnt] = (edge) {v, w, head[u]}, head[u] = cnt++;
}

void _insert(int u, int v, int w)
{
	_e[_cnt] = (edge) {v, w, _head[u]}, _head[u] = _cnt++;
}

void Tinsert(int u, int v)
{
	Te[Tcnt] = (edge) {v, 0, Thead[u]}, Thead[u] = Tcnt++;
}

void make_heap(int u)
{
	queue<Heap*> _q; h[u] = H[u] = null;
	for (int i = head[u]; ~i; i = e[i].next) {
		pii _v = make(delta[i], i);
		if (e[i].v == fa[u] && !delta[i]) fa[u] = 0;
		else _q.push(join(null, _v));
	}
	while (!_q.empty()) {
		h[u] = _q.front(); _q.pop();
		if (_q.empty()) return;
		Heap *_heap = _q.front();
		h[u] = marge(h[u], _heap);
		_q.pop(), _q.push(h[u]);
	}
}

void spfa()
{
	for (int i = 1; i <= n; i++)
		dis[i] = i == T ? 0 : inf;
	queue<int> _q; _q.push(T);
	
	while (!_q.empty()) {
		int u = _q.front(); vis[u] = 0, _q.pop();
		
		for (int i = _head[u]; ~i; i = _e[i].next) {
			int v = _e[i].v;
			if (dis[v] > dis[u] + _e[i].w) {
				dis[v] = dis[u] + _e[i].w, fa[v] = u;
				if (!vis[v]) vis[v] = 1, _q.push(v);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (i != T) Tinsert(fa[i], i);
	for (int i = 0; i < cnt; i++)
		delta[i] = e[i].w + dis[e[i].v] - dis[_u[i]];
	for (int i = 1; i <= n; i++)
		make_heap(i);
}

void dfs(int u)
{
	for (int i = Thead[u]; ~i; i = Te[i].next) {
		int v = Te[i].v;
		H[v] = marge(H[u], h[v]), dfs(v);
	}
}

typedef pair<int, pair<int, Heap*> > _Type;
priority_queue<_Type, vector<_Type>, greater<_Type> > q;

void Kshort()
{
	q.push(make(0, make(S, null)));
	
	while (dis[S] != inf && !q.empty() && K)  
	{
		_Type _top = q.top(); q.pop();
		ans = _top.fi, K -= 1;
		int u = _top.se.fi;
		Heap *_heap = _top.se.se; 
		int _delta = _heap -> val.fi;
		
		if (_heap -> ls != null) {
			Heap *_next = _heap -> ls; 
			int _pos = e[_next -> val.se].v; 
			int _w = _next -> val.fi - _delta;
			q.push(make(ans + _w, make(_pos, _next)));
		}
		if (_heap -> rs != null) {
			Heap *_next = _heap -> rs;
			int _pos = e[_next -> val.se].v;
			int _w = _next -> val.fi - _delta;
			q.push(make(ans + _w, make(_pos, _next)));
		}	
		if (H[u] != null) {
			int _pos = e[H[u] -> val.se].v;
			int _w = H[u] -> val.fi;
			q.push(make(ans + _w, make(_pos, H[u])));
		}	
	}
}

int main()
{
	n = read(), m = read(), init();
	
	memset(head, -1, sizeof head);
	memset(_head, -1, sizeof _head);
	memset(Thead, -1, sizeof Thead);
	
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		int w = read(); _u[cnt] = u;
		insert(u, v, w), _insert(v, u, w);
	}

	S = read(), T = read();
	K = read() + (S == T);
	spfa(), H[T] = h[T], dfs(T), Kshort();
	
	printf("%d\n", K ? -1 : ans + dis[S]);
	
	return 0;
}
