#include <cstdio>
#include <algorithm>
#define N 110
using namespace std;
struct node
{
    int u;
    int v;
    int w;
} edge[N*N]; //n个点有n^2条边啊啊啊啊TAT
int par[N];
bool cmp(node a,node b)
{
    return a.w<=b.w;
}
void init(int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        par[i]=i;
    }
}
int findpar(int x)
{
    if(x==par[x])
    {
        return x;
    }
    else
    {
        return findpar(par[x]);
    }
}
int kruskal(int d)
{
    int i,x,y,ans=0;
    //sort(edge+1,edge+1+d,cmp);
    for(i=1; i<=d; i++)
    {

        x=edge[i].u;
        y=edge[i].v;
        //printf("%d%d",x,y);
        x=findpar(x);
        y=findpar(y);
        //printf("%d%d",x,y);
        if(x!=y)
        {
            ans+=edge[i].w;
            par[y]=x;
            //printf("%d ",ans);
        }
    }
    return ans;
}
int main()
{
    int n,q,a,b,c,num;
    int i,j,ans;
    while(scanf("%d",&n)!=EOF)
    {
        init(n);
        num=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d",&a);
                if(i<j)
                {
                    edge[++num].u=i;
                    edge[num].v=j;
                    edge[num].w=a;
                    //printf("%d %d %d %d\n",num,i,j,a);
                }
                else
                {
                    continue;
                }
            }
        }
        scanf("%d",&q);
        for(i=1; i<=q; i++)
        {
            scanf("%d%d",&b,&c);
            b=findpar(b);
            c=findpar(c);
            par[c]=b;
            //printf("%d %d",par[b],par[c]);
        }
        sort(edge+1,edge+1+num,cmp);
        /*for(i=1;i<=num;i++){
            printf("%d %d %d %d\n",i,edge[i].u,edge[i].v,edge[i].w);
        }*/
        ans=kruskal(num);
        printf("%d\n",ans);
    }
    return 0;
}
