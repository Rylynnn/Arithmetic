/*************************************************************************
    > File Name: C.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年07月11日 星期二 16时32分40秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
#define INF 1e18
using namespace std;
struct node{
    ll l, r, cost;
}num[200007], end[200007];
bool cmp1(node a, node b)
{
    return a.l < b.l;
}
bool cmp2(node a, node b)
{
    return a.r < b.r;
}
ll n, x, j, now;
ll minm, ans[200007];
int main()
{
    cin >> n >> x;
    for(ll i=0;i<200007;i++){
        ans[i] = INF;
    }
    for (ll i=0;i<n;i++){
        cin >> num[i].l >> num[i].r >> num[i].cost;
        end[i].l = num[i].l;
        end[i].r = num[i].r;
        end[i].cost = num[i].cost;
    }
    sort(num, num+n, cmp1);
    sort(end, end+n, cmp2);
    minm = INF;
    j = 0;
    for (ll i=0;i<n;i++){
        //因为起点从小到大排序所以枚举更新其前面的区间可以降低复杂度
        while(j < n && end[j].r < num[i].l){
            ans[end[j].r - end[j].l + 1] = min(ans[end[j].r - end[j].l + 1], end[j].cost);
            j++;
        }
        now = x - (num[i].r - num[i].l + 1);
        if (now > 0 && ans[now] != INF && (ans[now] + num[i].cost) < minm){
            minm = ans[now] + num[i].cost;
        }
    }
    //cout << INF;
    if(minm == INF){
        cout << "-1" <<endl;
    }
    else{
        cout << minm << endl;
    }
    return 0;
}
