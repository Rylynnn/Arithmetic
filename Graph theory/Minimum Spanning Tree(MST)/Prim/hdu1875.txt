#include <cstdio>
#include <cmath>
#include <cstring>
#define N 110
#define MAX 0x3f3f3f3f
struct node{
    double x;
    double y;
}edge[N];
int c;
double m[N][N];
double getdis(node a,node b){
    /*double d;
    d=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    printf("lf ",d);*/
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void getmap(){
    int i,j;
    double dis;
    for(i=1;i<=c;i++){//日哦（i=c。。。= =
        m[i][i]=0;
        //printf("%lf",m[i][i]);
        for(j=i+1;j<=c;j++){
            dis=getdis(edge[i],edge[j]);
            //printf("%lf ",dis);
            if(dis>=10&&dis<=1000){
                m[i][j]=m[j][i]=dis;
            }
            else{
                m[i][j]=m[j][i]=MAX;
            }
        }
    }
}
void prim()
{
    double sum=0,minm;
    int t=c,i,d;
    int vis[N];
    memset(vis,0,sizeof(vis));
    while(--t){
        minm=MAX;
        for(i=2;i<=c;i++){
            if(!vis[i]&&m[1][i]<minm){//从2开始，不包含自己的点（
                minm=m[1][i];
                d=i;
            }
            //printf("%lf",minm);
        }
        if(minm==MAX){
            break;
        }
        vis[d]=1;
        sum+=minm;
        //printf("%lf ",sum);
        for(i=2;i<=c;i++){
            if(!vis[i]&&m[d][i]<m[1][i]){
                m[1][i]=m[d][i];
            }
        }
    }
    //printf("%d",t);
    if(t==0){
        printf("%.1f\n",sum*100);
    }
    else{
        printf("oh!\n");
    }

}
int main()
{
    //freopen("in,txt","r",stdin);
    int t,i;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&c);
            for(i=1;i<=c;i++){
                scanf("%lf%lf",&edge[i].x,&edge[i].y);
                //printf("%lf %lf\n",edge[i].x,edge[i].y);
            }
            getmap();
            prim();
        }
    }
    return 0;
}
