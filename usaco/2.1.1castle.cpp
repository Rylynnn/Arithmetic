/*
ID:15829681
LANG:C++
TASK:castle
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int a[57][57];
int n,m,r[2507],rr,maxmm,maxm,ansx,ansy,ansd;//r的长度应该是2500
int vis[57][57];
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
int dfs(int x,int y,int nn){
    int now;
    now=a[x][y];
    for(int tmp=0;tmp<4;tmp++){
        int t=now&1;
        //cout<<t<<endl;
        if(t==0){
            //cout<<x+dx[tmp]<<' '<<y+dy[tmp];
            if(!vis[x+dx[tmp]][y+dy[tmp]] && (x+dx[tmp]>0) && (x+dx[tmp]<=n) && (y+dy[tmp]>0) && (y+dy[tmp]<=m)){
                vis[x+dx[tmp]][y+dy[tmp]]=nn;
                rr++;
                dfs(x+dx[tmp],y+dy[tmp],nn);
            }
        }
        now=now>>1;
    }
    return rr;
}
void findwall(){
    for(int i=1;i<=m;i++){
        for(int j=n;j;j--){
            int now=a[j][i];
            int k[4];
            for(int tmp=0;tmp<4;tmp++){
                k[tmp]=now&1;
                now=now>>1;
            }
            if(k[1]==1){
                if(vis[j][i]!=0&&vis[j-1][i]!=0&&vis[j][i]!=vis[j-1][i]){
                    if(maxm<r[vis[j][i]]+r[vis[j-1][i]]){
                        maxm=r[vis[j][i]]+r[vis[j-1][i]];
                        ansx=j;
                        ansy=i;
                        ansd=1;
                    }
                }
            }
            if(k[2]==1){
                if(vis[j][i]!=0&&vis[j][i+1]!=0&&vis[j][i]!=vis[j][i+1]){
                    if(maxm<r[vis[j][i]]+r[vis[j][i+1]]){
                        maxm=r[vis[j][i]]+r[vis[j][i+1]];
                        ansx=j;
                        ansy=i;
                        ansd=2;
                    }
                }
            }
        }
    }
}
int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    memset(vis,0,sizeof(vis));
    memset(r,0,sizeof(r));
    int num=1;
    maxmm=maxm=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]){
                vis[i][j]=num;
                rr=1;
                r[num]=dfs(i,j,num);
                maxmm=max(maxmm,r[num]);
                num++;
            }
        }
    }
    findwall();
    printf("%d\n%d\n%d\n",num-1,maxmm,maxm);
    printf("%d %d ",ansx,ansy);
    if(ansd==1){
        printf("N\n");
    }
    else if(ansd==2){
        printf("E\n");
    }
}

