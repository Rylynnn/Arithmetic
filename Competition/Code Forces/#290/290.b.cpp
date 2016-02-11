#include<cstdio>
#include<cstring>
#include <iostream>

using namespace std;
const int maxn = 60;
char pic[maxn][maxn];
int m,n;
int vis[maxn][maxn];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool flag;

void dfs(int x1,int y1,int x2,int y2){
    //cout << x1 << " "  << y1 << " "<< x2 << " "<< y2 << " " << endl;

    if(flag) return;
    for(int k=0;k<4;k++)
    {
        if(0<=x2+dx[k]&&x2+dx[k]<n&&0<=y2+dy[k]&&y2+dy[k]<m
            && !(x2+dx[k] == x1 && y2+dy[k]==y1)
            && pic[x2+dx[k]][y2+dy[k]] == pic[x2][y2] )
        if(vis[x2+dx[k]][y2+dy[k]] == 0){
            flag = true;
            break;
        }
        else{
            vis[x2+dx[k]][y2+dy[k]] = 0;
            dfs(x2,y2,x2+dx[k],y2+dy[k]);
            //if(!flag) vis[x2+dx[k]][y2+dy[k]] = -1;
        }
    }
}


int main(){
   while(scanf("%d %d",&n,&m)!=EOF)
   {
       for(int i=0;i<n;i++)
       scanf("%s",pic[i]);
       memset(vis,-1,sizeof(vis));
       flag = false;
       for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
             if(vis[i][j]== -1)
                {
                 vis[i][j] = 0;
                 dfs(i,j,i,j);
                }
       if(flag){
           cout << "Yes" << endl;
       }
       else{
            cout << "No" << endl;
       }
   }
       return 0;
}
