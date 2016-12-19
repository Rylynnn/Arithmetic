#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
#include<cstdio>
#include<iomanip>
#include<string>
#include<set>
#include<cmath>
#include<cstring>
#include<map>
#include<algorithm>
#include<bitset>
#define lson (node<<1)
#define rson ((node<<1)|1)
#define mid  ((begin+end)>>1)
using namespace std;
const int inf = 0x3f3f3f3f;
const int inff = 0xfefefefe;
const int maxn = 200005;
typedef long long ll;
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
inline int read(){
	char c;
	int ans = 0;
	while ((c = getchar()) == '\n' || c == ' ' || c == '\r');
	ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans;
}

struct node {
	string name;
	vector<node> next;
	int deep;
}book[35];

bool cmp1(node a,node b) {
	return a.name < b.name;
}

string blank = "    ";

void dfs(node *n) {
	for (int i = 1; i < n->deep; i++)
		cout << blank;
	cout << n->name << endl;
	sort(n->next.begin(), n->next.end(), cmp1);
	for (int i = 0; i < n->next.size(); i++)
		dfs(&(n->next[i]));
}

int main() {
	string s;
	int Case = 1;
	while (cin>>s) {
		memset(book, 0, sizeof(book));
		if (s == "0")
			continue;
		int num = 0;
		do {
			string t = "";
			vector<string> v;
			for (int i = 0; i < s.size(); i++)
				if (s[i] == '/') {
					v.push_back(t);
					t = "";
				}
				else
					t += s[i];
			v.push_back(t);
			node *n = new node();
			bool flag = true;
			for (int i = 0; i < num; i++)
				if (book[i].name == v[0]) {
					free(n);
					n = &book[i];
					flag = false;
					break;
				}
			if (flag) {
				free(n);
				book[num].name = v[0];
				book[num].deep = 1;
				node *pre = &book[num];
				for (int i = 1; i < v.size(); i++) {
					n = new node();
					n->name = v[i];
					n->deep = pre->deep + 1;
					pre->next.push_back(*n);
					pre = n;
				}
				num++;
				cin >> s;
				continue;
			}
			int i;
			for (i = 1; i < v.size(); i++) {
				flag = true;
				for (int j = 0; j < n->next.size();j++)
					if (n->next[j].name == v[i]) {
						n = &(n->next[j]);
						flag = false;
						break;
					}
				if (flag) {
					break;
				}
			}
			if (flag) {
				node *pre = n;
				for (; i < v.size(); i++) {
					n = new node();
					n->name = v[i];
					n->deep = pre->deep + 1;
					pre->next.push_back(*n);
					pre = n;
				}
			}
			cin >> s;
		} while (s != "0");
		sort(book, book + num, cmp1);
		for (int i = 0; i < num; i++)
			dfs(&book[i]);
	}
	system("pause");
}
