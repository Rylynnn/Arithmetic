#include <set>  
#include <map>  
#include <cmath>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <string>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
typedef long long LL;  
#define FIN freopen("in.txt", "r", stdin);  
#define FOUT freopen("out.txt", "w", stdout);  
#define lson l, mid, cur << 1  
#define rson mid + 1, r, cur << 1 | 1  
const int INF = 0x3f3f3f3f;  
const int MAXN = (1 << 20) + 50;  
const int MOD = 1e9 + 7;  
  
int SG[MAXN];  
  
int DP(int state)  
{  
    if (SG[state] != -1)  
        return SG[state];  
    bool vis[22];  
    memset(vis, false, sizeof(vis));  
    for (int i = 19; i >=0; i--)  
    {  
        if ((state & (1 << i))){//找到可以移动的棋子  
        for (int j = i -1; j >=0; j--)//找到i右边最近的空格  
        {  
            if (!(state & (1 << j))) { 
            //state ^ (1 << i) ^ (1 << j)为state状态第i位移动到第j位后的状态  
            vis[DP(state - (1 << i) +(1 << j))] = true;   
            break;  
            }
        }  
        }
    }
   
    for (int i = 0; i < 22; i++)//找到最小的mex没有出现过的下标  
        if (vis[i] == 0)  
        {  
            SG[state] = i;  
            break;  
        }  
    return SG[state];  
}  
  
int main()  
{  
#ifndef ONLINE_JUDGE  
    FIN;  
#endif // ONLINE_JUDGE  
    memset(SG, -1, sizeof(SG));  
    for (int i = 0; i < (1 << 20); i++) { 
        DP(i);
      cout << SG[i] << endl;
    }
    int tcase;  
    scanf("%d", &tcase);  
    while (tcase--)  
    {  
        int n;  
        scanf("%d", &n);  
        int ans = 0;  
        for (int i = 0; i < n; i++)  
        {  
            int t, tstate = 0;  
            scanf("%d", &t);  
            for (int j = 0; j < t; j++)  
            {  
                int tt;  
                scanf("%d", &tt);  
                tstate |= (1 << (tt - 1));  
            }  
            ans ^= SG[tstate];  
        }  
        printf("%s\n", ans == 0 ? "NO" : "YES");  
    }  
    return 0;  
} 
