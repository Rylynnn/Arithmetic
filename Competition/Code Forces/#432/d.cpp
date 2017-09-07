/*************************************************************************
    > File Name: d.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 二  9/ 5 00:56:32 2017
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#define ll long long
#define N 1000007
#define INF 1e18//最大值标小了。。。。- -
using namespace std;
ll n, x, y, a[2*N+7], ans[2*N+7], num[2*N+7], fin, m;
ll check[N],prime[N];
ll getprime(){
    ll tot=0;
    memset(check,false,sizeof(check));
    check[0]=check[1]=true;
    for(ll i=2;i<N;i++){
        if(!check[i]){
            prime[tot++]=i;
        }
        for(ll j=0;j<tot;j++){
            if(i*prime[j]>N){
                break;
            }
            check[i*prime[j]]=true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    return tot;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> y;
	ll tot = getprime();
    memset(a, 0, sizeof(a));
    memset(num, 0, sizeof(num));
    memset(ans, 0, sizeof(ans));
    for(ll i=0; i<n; i++){
        cin >> m;
        a[m]++;
    }
    ans[0] = num[0] = 0;
    ll tmp = (x+y-1)/y;//选择删除还是增加的分界线
    for(ll i=1; i<=2*N; i++){
        num[i] = num[i-1], num[i] += a[i];
        ans[i] = ans[i-1], ans[i] += i * a[i]; 
        //cout << num[i] << ' ' << ans[i] << endl;
    }
    fin = INF;
    //cout << tmp << endl;
	for(ll i=0; i<tot; i++){
		ll mm = prime[i];
		ll cnt = 0;
		for(ll j=mm; j<=N+mm; j+=mm){
            if(num[j-1] - num[j-mm] > 0){
                if(mm <= tmp){
                    cnt += y * ((num[j-1] - num[j-mm]) * j - (ans[j-1] - ans[j-mm]));
                }
                else{
                    cnt += x * (num[j-tmp] - num[j-mm]) + y * ((num[j-1] - num[j-tmp]) * j - (ans[j-1] - ans[j-tmp]));
                }
            }
        }
        fin = min(fin, cnt);
    }
    cout << fin << endl;
    return 0;
}
