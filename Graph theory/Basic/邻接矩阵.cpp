#include<cstdio>
#include<cstring>
int main()
{
    int n,m,u,v,i,j,sum,point;
    int edge[110][110];
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(edge,0,sizeof(edge));
        for(i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            edge[u][v]=1;
        }
        point=1;
        for(i=1;i<=n;i++){
            sum=0;
            for(j=1;j<=n;j++){
                sum+=edge[i][j];
            }
            if(point){
                printf("%d",sum);
                point=0;

            }
            else printf(" %d",sum);
        }
        printf("\n");
        point=1;
        for(i=1;i<=n;i++){
            sum=0;
            for(j=1;j<=n;j++){
                sum+=edge[j][i];
            }
            if(point){
                printf("%d",sum);
                point=0;
            }
            else printf(" %d",sum);
        }
        printf("\n");
    }
    return 0;
}
