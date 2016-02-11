#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 110
#define MAX 0x3f3f3f3f3f
using namespace std;
long long l[5],c[5],d[N][N];
long long n,m;//RElong long写成了int
long long judge(long long g){
    if(g==0){
        return 0;
    }
    if(g>0&&g<=l[1]){
        return c[1];
    }
    if(g>l[1]&&g<=l[2]){
        return c[2];
    }
    if(g>l[2]&&g<=l[3]){
        return c[3];
    }
    if(g>l[3]&&g<=l[4]){
        return c[4];
    }
    return MAX;
}
long long labs(long long a){//wa1:longlong的abs重写
    return a<0?-a:a;
}
void Floyd(){
    long long i,j,k;
    for(k=1;k<=n;k++){
        for(j=1 ;  j<=n;j++){
            for(i=1;i<=n;i++){
                d[j][i]=min(d[j][i],d[j][k]+d[k][i]);
            }
        }
    }
}
int main(){
    //freopen("in.txt","r",stdin);
	long long t,i,j,e,f;
	long long b[N];
	while(scanf("%I64d",&t)!=EOF){
		long long a=0;
		while(++a<=t){
            memset(b,0,sizeof(b));
			scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&l[1],&l[2],&l[3],&l[4],&c[1],&c[2],&c[3],&c[4]);
			scanf("%I64d%I64d",&n,&m);
			for(i=1;i<=n;i++){
				scanf("%I64d",&b[i]);
			}
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(i!=j){
						d[i][j]=MAX;
					}
					else{
						d[i][j]=0;
					}
				}
			}
			for(i=1;i<=n;i++){
				for(j=i;j<=n;j++){
					d[i][j]=d[j][i]=judge(labs(b[i]-b[j]));
				}
			}
			Floyd();
			printf("Case %I64d:\n",a);
			for(i=1;i<=m;i++){
                scanf("%I64d%I64d",&e,&f);
                //printf("%d%d",e,f);
                if(d[e][f]==MAX){
                    printf("Station %I64d and station %I64d are not attainable.\n",e,f);
                }
                else{
                    printf("The minimum cost between station %I64d and station %I64d is %I64d.\n",e,f,d[e][f]);
                }
			}
		}
	}
}
