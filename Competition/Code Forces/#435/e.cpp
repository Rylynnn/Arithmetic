/*************************************************************************
    > File Name: e.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 二  9/19 23:29:14 2017
 ************************************************************************/
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 100005;

int n, m, q;
LL a[maxn], b[maxn], sum, tmp = 0;
vector<LL> g;
void get_ans(){
    int cnt = lower_bound(g.begin(), g.end(), sum)-g.begin();
    printf("%lld\n", min(abs(sum-g[cnt]), abs(sum-g[cnt-1])));
	while(q--){
        int l, r;LL x;
        scanf("%d%d%lld", &l, &r, &x);
        if((r-l+1)&1)
        {
            if(l&1)sum += x;
            else sum -= x;
        }
        cnt = lower_bound(g.begin(), g.end(), sum) - g.begin();
        printf("%lld\n", min(abs(sum - g[cnt]), abs(sum - g[cnt-1])));
    }
}
int main()
{
    g.push_back(-1e18);
	g.push_back(1e18);
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a[i]);
        if(i&1)sum += a[i];else sum -= a[i];
    }
    for(int i = 1;i <= m;i++){
		scanf("%lld", &b[i]);
	}
    for(int i = 1;i <= n;i++){
        if(i&1){
			tmp += b[i];
		}
		else tmp -= b[i];
	}
    g.push_back(tmp);
    for(int i = n+1;i <= m;i++){
        tmp -= b[i-n];
        tmp *= -1;
        if(n & 1){
			tmp += b[i];	
		}
		else tmp -= b[i];
        g.push_back(tmp);
    }
    sort(g.begin(), g.end());
	get_ans();
    return 0;
}
