/*************************************************************************
    > File Name: A.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年07月11日 星期二 17时37分38秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAXM 1000007
#define ll long long
using namespace std;
ll vis[MAXM], prime[MAXM];
ll getprime()
{
    ll tot = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = vis[1] = 1;
    for (int i=2;i<=MAXM;i++){
        if(!vis[i]){
            prime[tot++] = i;
        }
        for (int j=0;j<tot;j++){
            if (i * prime[j] > MAXM){
                break;
            }
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0){
                break;
            }
        }
    }
    return tot;
}
ll n;
int main()
{
    ll n;
    cin >> n;
    ll tot = getprime();
    for(int i=0;i<tot;i++){
        if(vis[n - prime[i]] == 0){
            cout << prime[i] << ' ' << n-prime[i] << endl;
            break;
        }
    }
    return 0;
}
