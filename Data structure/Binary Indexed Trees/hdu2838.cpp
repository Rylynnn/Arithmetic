#include <cstdio>
#include <cstring>
#define N 100010
#define lowbit(x) x&(-x)
int bit[N];
long long sum[N];
void update(int x){
	int t;
	t=x;
	while(x<N){
		bit[x]+=1;
		sum[x]+=t;
		x+=lowbit(x);
	}
}
long long getsum1(int x){
	long long s=0;
	while(x>0){
		s+=sum[x];
		x-=lowbit(x);
	}
	return s;
}
int getsum2(int x){
	int s=0;
	while(x>0){
		s+=bit[x];
		x-=lowbit(x);
	}
	return s;
}
int main()
{
	int n,a,i;
	long long k;
	while(scanf("%d",&n)!=EOF){
		long long ans=0;
		memset(bit,0,N);
		memset(sum,0,N);
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			update(a);//更新当前值的逆序对数和比他大的数之和
			k=i-getsum2(a);
			if(k!=0){
				ans+=k*a+getsum1(n)-getsum1(a);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
