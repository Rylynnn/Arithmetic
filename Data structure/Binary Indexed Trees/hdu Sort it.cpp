/*树状数组求逆序对数
可以把数一个个插入到树状数组中， 每插入一个数， 统计比他小的数的个数，对应的逆序为 i- getsum( data[i] )，其中 i 为当前
已经插入的数的个数， getsum( data[i] ）为比 data[i] 小的数的个数，
i- getsum( data[i] ) 即比 data[i] 大的个数， 即逆序的个数。最后需要把所有逆序数求和，就是在插入的过程中边插入边求和。*/
#include<cstdio>
#include<cstring>
#define N 1010
int bit[N];//用来
int lowbit(int x){
	return x&(-x);
}
void update(int x,int a){
	while(x<=N){
		bit[x]+=a;
		x+=lowbit(x);
	}
}
int getsum(int x){
	int sum=0;
	while(x>0){
		sum+=bit[x];
		x-=lowbit(x);
		//printf("%d\n",sum);
	}
	return sum;
}
int main()
{
	int n,i,a[N];
	int ans;
	while(scanf("%d",&n)!=EOF){
		ans=0;
		memset(bit,0,sizeof(bit));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			update(a[i],1);//用来表示a[i]插入之后，后面比他大的数字计算比自己小的数字时候需要
			ans+=i-getsum(a[i]);
			//printf("%d\n",ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
