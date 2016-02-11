#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#define eps 1e-10
using namespace std;
double M[220][220],dist[220];
int book[220];
struct Node
{
    double x,y,z,r;
}node[220];
int n;

int EPS(double k)
{
  if(fabs(k)<eps)
    return 0;
   return k>0?1:-1;
}

double dis(Node a,Node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))-a.r-b.r;
}

double prime(int cur)
{
    memset(book,0,sizeof(book));
    book[cur]=1;
    for(int i=1;i<=n;i++)
        dist[i]=M[cur][i];
    int index;
    double sum=0.0;
    for(int i=2;i<=n;i++)
    {
        double Min=99999999.0;
        for(int j=2;j<=n;j++)
        {
            if(!book[j]&&dist[j]<Min)
            {
                Min=dist[j];
                index=j;
            }
        }
        book[index]=1;
        sum+=Min;
        for(int j=2;j<=n;j++)
        {
            if(!book[j]&&M[index][j]<dist[j])
                dist[j]=M[index][j];
        }
    }
    return sum;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf %lf %lf %lf",&node[i].x,&node[i].y,&node[i].z,&node[i].r);
        memset(M,0,sizeof(M));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                double d=dis(node[i],node[j]);
                //printf("%ld",d);
                if(EPS(d)<=0)
                    M[i][j]=M[j][i]=0;
                else
                    M[i][j]=M[j][i]=d;
            }
        }
        cout<<fixed<<setprecision(3)<<prime(1)<<endl;
    }
}
