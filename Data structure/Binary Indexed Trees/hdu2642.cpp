#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 1010
using namespace std;
int bit[N][N];
int m[N][N];
int lowbit(int x){
	return x&(-x);
}
void update(int x,int y,int a){
	int t;
	while(x<N){
		t=y;
		while(t<N){
			bit[x][t]+=a;
			t+=lowbit(t);
		}
		x+=lowbit(x);
	}
}
int getsum(int x,int y){
	int t;
	int sum=0;
	while(x>0){
		t=y;
		while(t>0){
			sum+=bit[x][t];
			//printf("%d %d:%d ",x,t,sum);
			t-=lowbit(t);
		}
		x-=lowbit(x);
		//printf("\n");
	}
	return sum;
}
int main()
{
	int t,i,j,x,y,x1,y1,x2,y2;
	char obey;
	scanf("%d",&t);
	for(i=1;i<N;i++){
		for(j=1;j<N;j++){
			m[i][j]=0;
			bit[i][j]=0;
		}
	}
	while(t--){
		cin>>obey;
		if(obey=='B'){
			scanf("%d%d",&x,&y);
			x++,y++;
			if(m[x][y]==0){
				m[x][y]=1;
				update(x,y,1);
				//printf("%d %d:%d\n",x,y,bit[x][y]);
			}
		}
		if(obey=='D'){
			scanf("%d%d",&x,&y);
			x++,y++;
			if(m[x][y]==1){
				m[x][y]=0;
				update(x,y,-1);
			}
		}
		if(obey=='Q'){
			scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
			int x,y,xx,yy;
			xx=max(x1,x2),yy=max(y1,y2);
			x=min(x1,x2),y=min(y1,y2);
			x++,y++,xx++,yy++;
			//getsum(xx,yy);
			//getsum(x,yy);
			//getsum(xx,y);
			//getsum(x,y);
			printf("%d\n",getsum(xx,yy)-getsum(x-1,yy)-getsum(xx,y-1)+getsum(x-1,y-1));
		}
	}
	return 0;
}