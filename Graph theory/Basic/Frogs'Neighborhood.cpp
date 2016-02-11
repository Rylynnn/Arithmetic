#include<cstdio>
#include<algorithm>
#include<cstring>
#define LOCAL
using namespace std;
int edge[15][15];
struct vertex{
    int degree;
    int index;
};
vertex v[15];
bool cmp(vertex a,vertex b){
    return (b.degree)<(a.degree);
}
bool judge(int f,int e){
    int i;
    sort(v+f,v+e+1,cmp);//更新序列
    if(v[f].degree>e-f)return false;//如果目前的第一个数字大于后面的数字的数目，返回false
    if((v[f].degree)==0)return true;//如果排序完第一个为0，则返回false
    for(i=e;i>0;i--){
        //printf("%d",v[i].degree);
        if((v[i].degree)<0)return false;//如果剩下的数字中有负数则返回false
    }
   // printf("\n");
    for(i=f+1;i<f+1+v[f].degree;i++){
        v[i].degree--;//目前的第一个数字d之后的d个数字每个减1
        edge[v[f].index][v[i].index]=edge[v[i].index][v[f].index]=1;//填邻接矩阵
    }
    //for(i=f;i<=e;i++)printf("%d",v[i].degree);
    //printf("\n");
    return judge(f+1,e);
}
int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    #endif // Lacal
    int t,n,i,j,p;
    bool point;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&n);
            for(i=1;i<=n;i++){
                scanf("%d",&v[i].degree);
                v[i].index=i;
            }
            memset(edge,0,sizeof(edge));
            point=judge(1,n);
            if(point){
                printf("Yes\n");
                for(i=1;i<=n;i++){
                    p=1;
                    for(j=1;j<=n;j++){
                        if(p){printf("%d",edge[i][j]);p=0;}
                        else printf(" %d",edge[i][j]);
                    }
                    printf("\n");
                }
            }
            else printf("No\n");
            if(t)printf("\n");
        }
    }
    return 0;
}
