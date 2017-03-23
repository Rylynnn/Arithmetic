#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int m[20][20],ans=0,x,y,a,b;
void dfs(int xx,int yy){
    if(xx==a&&yy==b){
        ans++;
        return;
    }
    if(m[xx+1][yy]!=1&&(xx+1<=a)&&(yy<=b)){
        dfs(xx+1,yy);
    }
    if(m[xx][yy+1]!=1&&(xx<=a)&&(yy<=b)){
        dfs(xx,yy+1);
    }
    return;
}
int main()
{
    while(scanf("%d%d%d%d",&a,&b,&x,&y)!=EOF){
        ans=0;
        memset(m,0,sizeof(m));
        m[x-1][y-2]=1;
        m[x-2][y-1]=1;
        m[x-1][y+2]=1;
        m[x-2][y+1]=1;
        m[x+1][y-2]=1;
        m[x+2][y-1]=1;
        m[x+1][y+2]=1;
        m[x+2][y+1]=1;
        m[x][y]=1;
        /*for(int i=0;i<=a;i++){
            for(int j=0;j<=b;j++){
                cout<<m[i][j]<<' ';
            }
            cout<<endl;
        }*/
        dfs(0,0);
        printf("%d\n",ans);
    }
}
