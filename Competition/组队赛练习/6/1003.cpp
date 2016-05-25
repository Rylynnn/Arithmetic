#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAX 1000000000007
#define N 1007
#define ll long long
using namespace std;
ll s[N],p[N],mat[1007][1007],x[N*N],y[N*N],z[N*N];
ll vis[1000007],n;
void Dijkstra(){
    memset(s,0,sizeof(s));
    ll i,j,minm,t;
    for(i=1;i<n;i++){
        p[i]=mat[0][i];
    }
    s[0]=1;
    for(i=0;i<n;i++){
        minm=MAX;
        for(j=0;j<n;j++){
            if(!s[j]&&minm>p[j]){
                minm=p[j];
                t=j;
            }
        }
        if(minm==MAX){
            break;
        }
        s[t]=1;
        for(j=0;j<n;j++){
            if(!s[j]&&p[j]>minm+mat[t][j]){
                p[j]=minm+mat[t][j];
            }
        }
    }
}
int main(){
    ll m,xm=5837501,ym=9860381,zm=8475871;
    while(scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&n,&m,&x[0],&x[1],&y[0],&y[1])!=EOF){

        z[1]=((x[1]%zm)*90123%zm+y[1]%zm)%zm+1;
        z[0]=((x[0]%zm)*90123%zm+y[0]%zm)%zm+1;;
        for(int i=2;i<=n*n;i++){
            x[i]=(12345+((x[i-1]%xm)*23456)%xm+((x[i-2]%xm)*34567)%xm+((x[i-1]%xm)*(x[i-2]%xm)%xm)*45678%xm)%xm;
            y[i]=(56789+((y[i-1]%ym)*67890)%ym+((y[i-2]%ym)*78901)%ym+((y[i-1]%ym)*(y[i-2]%ym)%ym)*89012%ym)%ym;
            z[i]=((x[i]%zm)*90123%zm+y[i]%zm)%zm+1;
            //cout<<z[i]<<endl;
        }
        memset(mat,0,sizeof(mat));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    mat[i][j]=0;
                }
                else{
                    mat[i][j]=z[i*n+j];
                }
                //cout<<i<<' '<<j<<' '<<mat[i][j]<<endl;
            }
        }
        Dijkstra();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<n;i++){
            if(!vis[p[i]%m]){
                vis[p[i]%m]=1;

            }//cout<<p[i]<<' ';
        }
        for(int i=0;i<m;i++){
            if(vis[i]==1){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
