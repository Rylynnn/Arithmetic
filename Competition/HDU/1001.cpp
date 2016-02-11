#include <cstdio>
#include <cstring>
int v[105][105],n,m;
void add(){
    int i,j,t=0;
	if(v[1][n]==1||v[n][1]==1){
        printf("1 %d\n",((n-1)*(n))>>1);
	}
	else{
        printf("1 1\n");
	}
	return;
}
int main()
{
    int a,b,i;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(v,0,sizeof(v));//没有初始化的悲哀（日了狗了。。。
        for(i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            if(a!=b){
                v[a][b]=v[b][a]=1;
            }
        }
        add();
    }
    return 0;
}
