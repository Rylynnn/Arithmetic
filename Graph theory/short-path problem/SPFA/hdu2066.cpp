#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <algorithm>
#define N 1010
#define MAX 0x3f3f3f3f
using namespace std;
int t,s,d,n;
int b[N],e[N];
int v[N];
int p[N];
int c[N][N];
int spfa(){
    int i,now;
    queue<int>q;
    memset(v,0,sizeof(v));
    memset(p,0x3f,sizeof(p));
    for(i=1;i<=s;i++){
        p[b[i]]=0;
        v[b[i]]=1;
        q.push(b[i]);
    }
    while(!q.empty()){
        now=q.front();
        q.pop();
        v[now]=0;
        for(i=1;i<=n+1;i++){
            if(p[i]>p[now]+c[now][i]){
                p[i]=p[now]+c[now][i];
                if(!v[i]){
                    q.push(i);
                    v[i]=1;
                }
            }
        }
    }
    int minm=MAX;
    for(i=1;i<=d;i++){
        minm=min(minm,p[e[i]]);
    }
    return minm;
}
int main()
{
    int i,a,f,time;
    while(scanf("%d%d%d",&t,&s,&d)!=EOF){
        n=0;
        memset(c,0x3f,sizeof(c));
        memset(b,0,sizeof(b));
        memset(e,0,sizeof(e));
        for(i=1;i<=t;i++){
            scanf("%d%d%d",&a,&f,&time);
            if(c[a][f]>time){
                c[f][a]=c[a][f]=time;
            }
            n=max(n,max(a,f));
        }
        //printf("%d",n);
        /*for(i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }*/
        //printf("%d%d%d",t,s,d);
        for(i=1;i<=s;i++){
            scanf("%d",&b[i]);//ÈÕÅ¶¡£¡£ÍüÁË&¡£¡£¡£¡£TAT
            //printf("%d ",b[i]);
        }
        for(i=1;i<=d;i++){
            scanf("%d",&e[i]);
        }
        printf("%d\n",spfa());
    }
}
