#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define MAXN 50001
#define N 1000007
#define ll long long
#define INF 0x3f3f3e3d
using namespace std;
struct Edge{
	int id, width, next;
	ll cost;
}node[N];
int head[MAXN], tmp, poi_num, dist, num;
ll d[MAXN];
bool vis[MAXN];
void add(int s, int id, int width, ll cost){//链式前向星建图
	node[num].id = id;
    node[num].width = width;
    node[num].next = head[s];
    node[num].cost = cost;
	head[s] = num++;
	node[num].id = s;
    node[num].width = 0;
    node[num].next = head[id];
    node[num].cost = -cost;
	head[id] = num++;
}
bool SPFA(){
	static pair<ll, int> q[MAXN];
	memset(d, INF, sizeof(ll)*(tmp + 1));
	memset(vis + 1, 0, sizeof(bool)*tmp);
	d[dist] = 0; q[0] = make_pair(0, dist);
	for (int pos = 1; pos;){
		int i = q->second;
		pop_heap(q, q + pos--);
		if (vis[i])continue;
		vis[i] = true;
		for (int j = head[i]; j != -1; j = node[j].next){
			int t = node[j].id;
			if (node[j ^ 1].width && d[t] > d[i] - node[j].cost){
				d[t] = d[i] - node[j].cost;
				q[pos++] = make_pair(-d[t], t);
				push_heap(q, q + pos);
			}
		}
	}
	return d[poi_num] < d[0];
}
int dfs(int i, int flow){
	if (i == dist)return flow;
	vis[i] = true;
	int ret = 0;
	for (int j = head[i]; j != -1; j = node[j].next){
		if (!node[j].cost && node[j].width && !vis[node[j].id]){
			int w = dfs(node[j].id, min(flow - ret, node[j].width));
			node[j].width -= w; node[j ^ 1].width += w; ret += w;
			if (ret == flow)break;
		}
	}
	if (ret)vis[i] = false;
	return ret;
}
ll costFlow(){
	ll ret = 0, dis = 0;
	while (SPFA()){
		for (int i = 1; i <= tmp; i++){
			for (int j = head[i]; j != -1; j = node[j].next){
				node[j].cost += d[node[j].id] - d[i];
		    }
        }
		dis += d[poi_num];
		memset(vis + 1, 0, sizeof(bool)*tmp);
		ll tmp = dis * dfs(poi_num, INF);
		if(tmp < 0){
            ret += tmp;
	    }
    }
	return ret;
}
int main()
{
	int n, m, a, b, c, d, e, f, g;
	while(scanf("%d%d", &n, &m)!=EOF){
	    num = 0; tmp = n + 2;
		poi_num = n + 1;
        dist = n + 2;
	    memset(head + 1, -1, sizeof(int) * (n + 2));
		for(int i=1; i<=n; i++){
			scanf("%d%d%d%d", &a, &b, &c, &d);
			add(poi_num, i, b, a);
			add(i, dist, d, -c);
		}
		for(int i=0; i<m; i++){
			scanf("%d%d%d", &e, &f, &g);
			add(e, f, INF, g);
			add(f, e, INF, g);
		}
		printf("%lld\n", -costFlow());
	}
}
