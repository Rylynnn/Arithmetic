/*************************************************************************
    > File Name: 1001.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 日  9/10 12:20:13 2017
 ************************************************************************/

//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#define ll long long
using namespace std;

const int maxn=100100;
const int inf=0x3f3f3f3f;
int wa[maxn],wb[maxn],wn[maxn],wv[maxn];
int rk[maxn],height[maxn],sa[maxn],r[maxn];
string str;

int cmp(int *r,int a,int b,int l)
{
    return (r[a]==r[b])&&(r[a+l]==r[b+l]);
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wn[i]=0;
    for(i=0;i<n;i++) wn[x[i]=r[i]]++;
    for(i=1;i<m;i++) wn[i]+=wn[i-1];
    for(i=n-1;i>=0;i--) sa[--wn[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wn[i]=0;
        for(i=0;i<n;i++) wn[wv[i]]++;
        for(i=1;i<m;i++) wn[i]+=wn[i-1];
        for(i=n-1;i>=0;i--) sa[--wn[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++) rk[sa[i]]=i;
    for(i=0;i<n;height[rk[i++]]=k )
    for(k?k--:0,j=sa[rk[i]-1];r[i+k]==r[j+k];k++);
}
int d_min[maxn][20];  
  
  
void RMQ_init(int n)  
{  
    for(int i = 1; i <= n; i++)  
    {  
        d_min[i][0] = height[i]; // 2^0 = 1  
    }  
    for(int j = 1; (1<<j) <= n; j++) // 2^j <= n  
    {  
        for(int i = 1; i+(1<<j)-1 <= n; i++) // i+2^j-1 <= n  
        {  
            d_min[i][j] = min(d_min[i][j-1], d_min[i+(1<<(j-1))][j-1]);  
        }  
    }     
}  
  
int get_rmq(int L, int R)  
{  
    int k = 0;  
    while((1<<(k+1)) <= R-L+1) k++; // 如果 2^(k+1) <= R-L+1,那么k 还可以加 1   
    return min(d_min[L][k], d_min[R-(1<<k)+1][k]);  
}  
ll check(int k, int n){
    ll now = 0;
    ll i = 1;
	height[n+1] = 0;
    while(i+k-1 <= n){
        ll j = i + k - 1;
        ll p = max(height[i], height[j+1]);
        ll q;
        if(i == j){
            q = n - sa[i];
        }
        else{
            q = get_rmq(i+1, j);
        }
        if(q > p){
            now += q - p;
        }
        i++;
    }
    return now;
}
int main()
{
    //freopen("1.in","r",stdin);
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(int o=1;o<=T;o++)
    {
		int k;
        cin >> k;
        cin >> str;
		int n=str.size();
		memset(r, 0, sizeof(r));
        for(int i=0;i<n;i++)
            r[i]=str[i];
        r[n]=0;
        da(r,sa,n+1,256);
        calheight(r,sa,n);
		RMQ_init(n);
        ll ans = check(k, n);
        cout << ans << endl;
    }
    return 0;
}



