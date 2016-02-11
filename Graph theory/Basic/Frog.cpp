#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 15
#define LOCAL
using namespace std;

struct Node
{
    int dn,id;
    bool operator<(const Node & a)const
    {
        return dn>a.dn;
    }
}node[N];

int gra[N][N];
int n;

void re(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        node[i].id=i;
        scanf("%d",&node[i].dn);
    }
}

void run(void)
{
    memset(gra,0,sizeof(gra));
    int flag=0;
    for(int i=1;i<=n&&!flag;i++)
    {
        sort(node+i,node+1+n);
        if(node[i].dn+i>n)
        {
            flag=1;
            break;
        }
        for(int j=1;j<=node[i].dn;j++)
        {
            int a=node[i].id,b=node[i+j].id;
            gra[a][b]=gra[b][a]=1;
            node[i+j].dn--;
            if(node[i+j].dn<0)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag)
        puts("NO");
    else
    {
        puts("YES");
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j!=1)printf(" ");
                printf("%d",gra[i][j]);
            }
            puts("");
        }
    }
}


int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    #endif // Lacal
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        re();
        run();
        if(ncase)
            puts("");
    }
    return 0;
}
