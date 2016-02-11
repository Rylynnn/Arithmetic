#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 1010
#define MAX 0x3f3f3f3f
using namespace std;
int n,m,c;
int a[N][N];
int p[N],s[N];
void Dijkstra(int b){//重点确定所以从终点反向做
	int i,j,t;
	memset(s,0,sizeof(s));
	for(i=1;i<=n;i++){
		p[i]=a[b][i];
	}
	s[b]=1;
	for(i=1;i<=n;i++){
		int mi=MAX;
		for(j=1;j<=n;j++){
			if(!s[j]&&mi>p[j]){
				mi=p[j];
				t=j;
			}
		}
		/*if(t==e){
			return p[e];
		}*/
		if(mi==MAX){
			return;
		}
		s[t]=1;
		for(j=1;j<=n;j++){
			if(!s[j]&&p[j]>mi+a[t][j]){
				p[j]=mi+a[t][j];
			}
		}
	}
	return;
}
int main()
{
    int i,j,d,q,t,w,b,minm;
    while(scanf("%d%d%d",&n,&m,&c)!=EOF){
    	for(i=1;i<=n;i++){
    		for(j=1;j<=n;j++){
    			if(i==j){
    				a[i][j]=0;
    			}
    			else{
    				a[i][j]=MAX;
    			}
    		}
    	}
    	for(i=1;i<=m;i++){
    		scanf("%d%d%d",&d,&q,&t);
    		if(t<a[q][d]){//wa1:防止重边！！！！
                a[q][d]=t;
    		}
    	}
    	Dijkstra(c);
    	scanf("%d",&w);
    	minm=MAX;
    	for(i=1;i<=w;i++){
    		scanf("%d",&b);
    		if(p[b]!=MAX){//与某些变量重名。。
    			minm=min(minm,p[b]);
    		}
    	}
    	if(minm!=MAX){
    		printf("%d\n",minm);
    	}
    	else{
    		printf("-1\n");
    	}
    }
}
