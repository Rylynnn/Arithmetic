/*************************************************************************
    > File Name: A.cpp
    > Author: wmg_1001
    > Mail: wmg_1007@163.com
    > Created Time: 2015年02月04日 星期三 03时22分01秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <set>
using namespace std;

const int MAXN = 205;
const int MAXM = 20005;

struct graph_node {
	int next, to;
}graph[MAXM];

int match[MAXN], nx, ny, head[MAXN], tot_len;
int A[MAXN], B[MAXN];
bool vis[MAXN];

void addedge(int p1, int p2) {
	graph[tot_len].next = head[p1];
	graph[tot_len].to = p2;
	head[p1] = tot_len++;
}

bool find_path(int p) {
	for (int i = head[p]; i != -1; i = graph[i].next) {
		int v = graph[i].to;
		if (!vis[v]) {
			vis[v] = true;
			if (match[v] == -1 || find_path(match[v])) {
				match[v] = p;
				return true;
			}
		}
	}
	return false;
}

int MaxMatch(void) {
	memset(match, -1, sizeof(match));
	int res = 0;
	for (int i = 0; i < nx; i++) {
		memset(vis, false, sizeof(vis));
		if (find_path(i)) res++;
	}
	return res;
}

int main() {
	while (scanf("%d", &nx) != EOF) {
		for (int i = 0; i < nx; i++) cin >> A[i];
		cin >> ny;
		for (int i = 0; i < ny; i++) cin >> B[i];
		memset(head, -1, sizeof(head));
		tot_len = 0;
		for (int i = 0; i < nx; i++)
			for (int j = 0; j < ny; j++)
				if (abs(A[i] - B[j]) <= 1) addedge(i, j + nx);
		cout << MaxMatch() << endl;
	}
	return 0;
}
