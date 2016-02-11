/*
树状数组模拟动态规划
RE1:调试时候改了N忘了改回来
WA1：重点！！！！更新和求和均要摸mod！！！！
*/
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
bool cmp(node a,node b){
	return a.v<b.v;
}
int main()
{
	int num,i;
	while(scanf("%d",&num)!=EOF){
		memset(b,0,sizeof(b));
		memset(bit,0,sizeof(bit));
		for(i=1;i<=num;i++){
			scanf("%d",&a[i].v);
			a[i].n=i;
		}
		sort(a+1,a+1+num,cmp);
		b[a[1].n]=1;//离散化重点
		for(i=2;i<=num;i++){
			if(a[i].v!=a[i-1].v){
				b[a[i].n]=i;
			}
			else{
				b[a[i].n]=b[a[i-1].n];
			}

		}
		for(i=1;i<=num;i++){/*离散化之后的序列做的处理为将原数组的数值变为了计算了重复数字之后
			的数值如：2 2 3 1变为2 2 4 1*/
            int k=getsum(b[i])+1;
			update(b[i],k);//每次计算以该数为结尾的顺序集合为多少

		}
		printf("%d\n",getsum(num));
	}
	return 0;
}
