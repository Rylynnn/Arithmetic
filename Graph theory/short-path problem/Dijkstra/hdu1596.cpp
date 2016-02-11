#include <cstdio>
#include <cstring>
#define eps 10e-6
#define N 1010
//#define MAX 0x3f3f3f3f
double a[N][N];
int s[N];
double p[N];
int n;
void Dijkstra(int b,int e){
    int i,j,t=0;
	memset(s,0,sizeof(s));
	for(i=1;i<=n;i++){
		p[i]=a[b][i];
	}
	s[b]=1;
	for(i=1;i<n;i++){
		double maxm=0;//double！！！！！！日哦
		for(j=1;j<=n;j++){
			if(!s[j]&&p[j]-maxm>eps){
				maxm=p[j];//j变成了i要死。。。。
				t=j;
			}
		}
		/*if(maxm<eps){
            if(!p[e]){
                printf("What a pity!\n");
                return;
            }
            else{
                printf("%.3lf\n",p[e]);
                return;
            }
        }*/
        if(t==e){
            printf("%.3lf\n",p[e]);
            return;
        }
		s[t]=1;
		for(j=1;j<=n;j++){
			if(!s[j]&&a[t][j]>eps&&maxm*a[t][j]-p[j]>eps){
				p[j]=maxm*a[t][j];
			}
		}
	}
    printf("What a pity!\n");
    return;
}
int main(){
	int i,j,q,b,c;
    while(scanf("%d",&n)!=EOF){
        //printf("%d",n);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%lf",&a[i][j]);
                //printf("%lf",a[i][j]);
			}
		}
		scanf("%d",&q);
		for(i=1;i<=q;i++){
			scanf("%d%d",&b,&c);
			Dijkstra(b,c);
		}
	}
}
