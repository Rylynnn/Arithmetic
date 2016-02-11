/*
《浅谈信息学竞赛中的"0"和"1"   —二进制思想在信息学竞赛中的应用》
getsum(x)mod2计算x被修改的次数

*/#include <cstdio>
#define N 110
#define lowbit(x) x&(-x)
int bit[N][N][N];
int matic[N][N][N];
void update(int x,int y,int z){
	int a,b;
	while(x<N){
		a=y;
		while(a<N){
			b=z;
			while(b<N){
				bit[x][a][b]++;
				b+=lowbit(b);
			}
			a+=lowbit(a);
		}
		x+=lowbit(x);
	}
}
int getsum(int x,int y,int z){
	int sum=0;
	int a,b;
	while(x>0){
		a=y;
		while(a>0){
			b=z;
			while(b>0){
				sum+=bit[x][a][b];
				b-=lowbit(b);
			}
			a-=lowbit(a);
		}
		x-=lowbit(x);
	}
	return sum;
}
void initial(){
	int i,j,k;
	for(i=1;i<N;i++){
		for(j=1;j<N;j++){
			for(k=1;k<N;k++){
				bit[i][j][k]=0;
			}
		}
	}
}
int main()
{
	int n,m,x;
	int i;
	int x1,x2,x3,y1,y2,y3,z1,z2,z3;
	while(scanf("%d%d",&n,&m)!=EOF){
		initial();
		for(i=1;i<=m;i++){
			scanf("%d",&x);
			if(x==1){//先从最右下角的开始做，下改上恢复，然后消除队友左边空间的影响（下改上恢复），然后消除后方空间的影响（下改上恢复），最后消除中间空间的影响
				scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
				update(x1,y1,z1);
				update(x1,y1,z2+1);
				update(x1,y2+1,z1);
				update(x1,y2+1,z2+1);
				update(x2+1,y1,z1);
				update(x2+1,y1,z2+1);
				update(x2+1,y2+1,z1);
				update(x2+1,y2+1,z2+1);
			}
			if(x==0){
				scanf("%d%d%d",&x3,&y3,&z3);
				printf("%d\n",getsum(x3,y3,z3)&1);//等价于getsum（x）mod2
			}
		}
	}
	return 0;
}