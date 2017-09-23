#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 50001
struct Edge{
	int t, w, next;
}e[1000001];
int head[MAXN], layer[MAXN], num[MAXN];
int cnt, src, dst, cur;
void init(int n)
{
	cur = 0; cnt = n;
	memset(head + 1, -1, sizeof(int)*n);
}
void addEdge(int s, int t, int w)
{
	e[cur] = { t, w, head[s] };
	head[s] = cur++;
	e[cur] = { s, 0, head[t] };
	head[t] = cur++;
}
void addEdge2(int s, int t, int w)
{
	e[cur] = { t, w, head[s] };
	head[s] = cur++;
	e[cur] = { s, w, head[t] };
	head[t] = cur++;
}
int dfs(int i, int flow)
{
	if (i == dst)return flow;
	int ret = 0, h = cnt;
	for (int j = head[i]; j != -1; j = e[j].next){
		if (e[j].w){
			if (layer[i] == layer[e[j].t] + 1){
				int w = dfs(e[j].t, min(flow - ret, e[j].w));
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
int isap()
{
	int res = 0;
	memset(layer + 1, 0, sizeof(int)*cnt);
	memset(num, 0, sizeof(int)*cnt);
	num[0] = cnt;
	while (layer[src] < cnt)res += dfs(src, 0x7fffffff);
	return res;
}