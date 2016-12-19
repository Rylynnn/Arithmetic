#include <bits/stdc++.h>
#define eps 1e-6
#define MAX 100007
#define ll long long
#define MOD 1000000007
using namespace std;
ll flag[2010],prime[2007],ans,cnt=0;
void getprime(){
    memset(flag,0,sizeof(flag));
    for(ll i=2;i<=2008;i++){
        if(flag[i]) continue;
        prime[cnt++]=i;
        for(ll j=2;j*i<=2008;j++)
            flag[i*j]=1;
    }
}
const ll MAXN=2007;
ll a[MAXN][MAXN],num[307],n;//增广矩阵
ll x[MAXN];//解集
bool free_x[MAXN];//标记是否是不确定的变元

int main()
{
    ll t,m;
    getprime();
    while(scanf("%I64d",&t)!=EOF){
        for(ll i=0;i<=cnt;i++){
            printf("%I64d,",prime[i]);
        }
        cout<<cnt;
    }
}
