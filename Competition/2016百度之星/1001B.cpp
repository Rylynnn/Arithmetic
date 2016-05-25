#include <cstdio>
#include <cstring>
#include <algorithm>
#define mod 1000000007
#define N  100100
#define lowbit(x) x&(-x)
using namespace std;
struct node{
	int n,v;
}a[N];
int bit[N];
int b[N];
int getsum(int x){
	int sum=0;
	while(x>0){
		sum+=bit[x];
		sum%=mod;
		x-=lowbit(x);
	}
	return sum;
}
void update(int x,int add){
	while(x<=N){
		bit[x]+=add;
		bit[x]!=mod;
		x+=lowbit(x);
	}
}
