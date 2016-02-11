#include <cstdio>
#include <cstring>
#define MAX 0x3f3f3f3f//MAX值得控制问题！！！！！！！！！！！
int edge[1001][1001];
int s[1001],p[1001];
int n,m;
void dijktra(){
    int i,j,t;
    memset(s,0,sizeof(s));
    /*for(i=1;i<=n;i++){
        p[i]=MAX;
    }*/
    for(i=1;i<=n;i++){
        p[i]=edge[1][i];
    }
    s[1]=1;
    int minm;
    for(i=1;i<=n;i++){
        minm=MAX;
        for(j=1;j<=n;j++){
            if(!s[j]&&p[j]<minm){
                minm=p[j];
                t=j;
            }
        }
        s[t]=1;
        for(j=1;j<=n;j++){
            if(!s[j]&&p[j]>minm+edge[t][j]){//更新啊啊啊啊要更新的是p
                p[j]=minm+edge[t][j];
            }
        }
    }
}//各种手误i，j写错啊啊啊啊啊
int main()
{
    int i,j;
    int a,b,l;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0){
            break;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                edge[i][j]=MAX;
                /*if(i==j){
                    edge[i][j]=0;
                }*/
            }
        }
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&a,&b,&l);
                edge[a][b]=edge[b][a]=l;
        }
        /*for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                printf("%d ",edge[i][j]);
            }
            printf("\n");
        }*/
        dijktra();

        printf("%d\n",p[n]);
    }
}
