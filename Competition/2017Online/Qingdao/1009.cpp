/*************************************************************************
    > File Name: 1009.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/17 13:26:37 2017
 ************************************************************************/
#include <bits/stdc++.h>
#define MAXN 207
#define MAXM 1007
#define ll long long
using namespace std;
struct Edge{
	ll t, w, next;
}e[MAXM];
ll head[MAXN], layer[MAXN], num[MAXN];
ll cnt, src, dst, cur;
void init(ll n)
{
	cur = 0; cnt = n;
	memset(head + 1, -1, sizeof(ll)*n);
}
void addEdge(ll s, ll t, ll w)
{
	e[cur] = { t, w, head[s] };
	head[s] = cur++;
	e[cur] = { s, 0, head[t] };
	head[t] = cur++;
}
void addEdge2(ll s, ll t, ll w)
{
	e[cur] = { t, w, head[s] };
	head[s] = cur++;
	e[cur] = { s, w, head[t] };
	head[t] = cur++;
}
ll dfs(ll i, ll flow)
{
	if (i == dst)return flow;
	ll ret = 0, h = cnt;
	for (ll j = head[i]; j != -1; j = e[j].next){
		if (e[j].w){
			if (layer[i] == layer[e[j].t] + 1){
				ll w = dfs(e[j].t, min(flow - ret, e[j].w));
				e[j].w -= w; e[j ^ 1].w += w;
				ret += w;
				if (ret == flow || layer[src] >= cnt)return ret;
			}
			h = min(h, layer[e[j].t]);
		}
	}
	if (!ret){
		if (!--num[layer[i]])layer[src] = cnt;
		layer[i] = h + 1; num[layer[i]]++;
	}
	return ret;
}
ll isap()
{
	ll res = 0;
	memset(layer + 1, 0, sizeof(ll)*cnt);
	memset(num, 0, sizeof(ll)*cnt);
	num[0] = cnt;
	while (layer[src] < cnt)res += dfs(src, 0x7fffffff);
	return res;
}
int main(){
    ll _case, u, v, w, n, m, s, t;
    scanf("%lld",&_case);
    while(_case--){
        scanf("%lld%lld", &n, &m);
		scanf("%lld%lld", &s, &t);
        src = s, dst = t;
		init(n);
        for(ll i=1;i<=m;i++){
            scanf("%lld%lld%lld",&u,&v,&w);
            addEdge(u,v,(ll) w * MAXM + 1);
        }
        ll ans=isap();
        printf("%lld\n", ans % MAXM);
    }
    return 0;
}
