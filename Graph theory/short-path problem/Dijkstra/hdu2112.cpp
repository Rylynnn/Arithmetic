/*
    提前return的话，可能有结果的最短路已经算出但是起点不一定能到达所有的的点。
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#define N 200
#define MAX 0x3f3f3f3f
using namespace std;
int s[N],p[N];
int c[N][N];
int n,num;
void Dijkstra(){
    memset(s,0,sizeof(s));
    int i,j,minm,t;
    for(i=1;i<=num;i++){
        p[i]=c[1][i];
    }
    s[1]=1;
    for(i=1;i<=num;i++){
        minm=MAX;
        for(j=1;j<=num;j++){
            if(!s[j]&&minm>p[j]){
                minm=p[j];
                t=j;
            }
        }
        if(minm==MAX){
            break;
        }
        s[t]=1;
        for(j=1;j<=num;j++){
            if(!s[j]&&p[j]>minm+c[t][j]){
                p[j]=minm+c[t][j];
            }
        }
    }
}
int main()
{
    char b[35],e[35],a[35],d[35];
    int dis,i,j;
    while(scanf("%d",&n)!=EOF){
        if(n==-1){
            break;
        }
        map<string,int>m;
        m.clear();
        cin>>b>>e;
        m[b]=1;
        m[e]=2;
        num=2;
        //printf("%d ",num);
        memset(c,MAX,sizeof(c));
        for(i=1;i<200;i++){
            c[i][i]=0;
        //原来写成了i<=200结果直接错的莫名其妙啊= =
        }
        //printf("%d",num);
        for(i=1;i<=n;i++){
            cin>>a>>d>>dis;
            if(!m[a]){
                m[a]=++num;
            }
            if(!m[d]){
                m[d]=++num;
            }
            if(dis<c[m[a]][m[d]]){
                c[m[a]][m[d]]=c[m[d]][m[a]]=dis;
            }
        }
        //printf("%d",num);
        if(!strcmp(b,e)){
            printf("0\n");
            continue;
        }
        Dijkstra();
        if(p[2]!=MAX){
            printf("%d\n",p[2]);
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
