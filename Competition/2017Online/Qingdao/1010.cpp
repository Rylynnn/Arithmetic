/*************************************************************************
    > File Name: 1010.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/17 14:41:56 2017
 ************************************************************************/
#include <bits/stdc++.h>
#define N 100007
using namespace std;
int p[N], pre[N], nxt[N], vis[N];
void dfs(int poi){
	int now = 0;
	memset(vis, 0, sizeof(vis));
	while(1){
		now = nxt[now];
		if(now != 1 && p[now] < p[pre[now]]){
			vis[now] = 1;
            poi = 1;
		}
        if(nxt[now] == -1){
            break;  
        }
	}
	while(pre[now] != -1){
		now = pre[now];
		if(p[now] > p[nxt[now]]){
			vis[now] = 1;
            poi = 1;
		}	
	}
	now = 0;
	while(nxt[now] != -1){
		now = nxt[now];
		if(vis[now] == 1){
			p[now] = 0;
			nxt[pre[now]] = nxt[now];
			pre[nxt[now]] = pre[now];
		}
	}
	now = 0;
	while(1){
		now = nxt[now];
		cout << now << ' ' << pre[now] << ' ' << nxt[now] << endl;
        if(nxt[now] == -1){
            break;
        }
	}
    if(poi == 1){
        dfs(0);
    }
    return;
}	
int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        nxt[0] = -1;
        pre[0] = -1;
        memset(p, 0, sizeof(p));
        for(int i=1; i<=n; i++){
            scanf("%d", &p[i]);
            nxt[i] = nxt[i-1];
            nxt[i-1] = i;
            pre[i] = i-1;
        }
        dfs(0);
        int now = 0, num = 0;
        while(1){
		    now = nxt[now];
            num++;
		    cout << now << ' ' << pre[now] << ' ' << nxt[now] << endl;
            if(nxt[now] == -1){
                break;
            }
	    }
        cout << num << ' ';
        while(1){
            now = nxt[now];
            cout << p[now] << ' ';
        }
        cout << endl;
	}
	return 0;
}
