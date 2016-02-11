#include<cstdio>
int vis[MAX][MAX];
int main()
{
    int n,m;
    char a[210][210];
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%c",a[i][j]);
                if(a[i][j]=='Y'){
                    yi=i;
                    yj=j;
                    vis[i][j]=1;
                }
                if(a[i][j]=='M'){
                    mi=i;
                    mj=j;
                    vis[i][j]=1;
                }
            }
        }
    }
}
bool bfs(int x,int y,int p,int q){
    vis[x][y]=1;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;i++){
            if(vis[x+i][y+i]!=1&&((i!=0&&j!=0)&&((x+i)>0&&(x+i)<n)||((y+j)>0&&(y+j)<m)){
                next[x+i][x+j]=k;
                if(a[x+i,y+j]=='@'){
                    if(k<point)point=k;
                    return true;
                }

            }
        }
    }
    k+=1;
}
