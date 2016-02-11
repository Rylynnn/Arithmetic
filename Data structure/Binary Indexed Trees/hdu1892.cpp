/*
RE点：N不能等于？以及算和的时候，边界没有处理好
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#define N 1100
using namespace std;
int matix[N][N];
int bit[N][N];
int n;
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
			t-=lowbit(t);
		}
		x-=lowbit(x);
	}
	//printf("%d\n",sum);
	return sum;
}
int main()
{
	int t,i,j,x1,y1,x2,y2,n1;
	char obey;
	while(scanf("%d",&t)!=EOF){
	    int k=1;
		while(t--){
			scanf("%d",&n);
			for(i=1;i<N;i++){
				for(j=1;j<N;j++){
					matix[i][j]=1;
					bit[i][j]=lowbit(i)*lowbit(j);
					//printf("%d ",bit[i][j]);
				}
				//printf("\n");
			}
			printf("Case %d:\n",k++);
			for(i=1;i<=n;i++){
				cin>>obey;
				if(obey=='S'){//对角线有左右两条而且有可能顶点大小不一
					scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
					//printf("sada\n");
					int x,y,xx,yy;
					x=min(x1,x2),xx=max(x1,x2);
                	y=min(y1,y2),yy=max(y1,y2);
                	x++,y++,xx++,yy++;
					printf("%d\n",getsum(xx,yy)-getsum(xx,y-1)-getsum(x-1,yy)+getsum(x-1,y-1));
				}
				else if(obey=='A'){
					scanf("%d%d%d",&x1,&y1,&n1);
					x1++;
					y1++;
					update(x1,y1,n1);
					matix[x1][y1]+=n1;
				}
				else if(obey=='D'){
					scanf("%d%d%d",&x1,&y1,&n1);
					x1++;
					y1++;
					if(matix[x1][y1]<n1){
						n1=matix[x1][y1];
					}
					update(x1,y1,-n1);
					matix[x1][y1]-=n1;
				}
				else if(obey=='M'){//如果取得书大于本身有的书则全部取出
					scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&n1);
					x1++;
					y1++;
					x2++;
					y2++;
					if(matix[x1][y1]<n1){
                        n1=matix[x1][y1];
					}
                    update(x1,y1,-n1);
                    update(x2,y2,n1);
                    matix[x1][y1]-=n1;
                    matix[x2][y2]+=n1;
				}
			}
		}
	}
	return 0;
}
