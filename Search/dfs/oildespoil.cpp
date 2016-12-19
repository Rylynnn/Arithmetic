#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string a[107];
int m,n;
void dfs(int x,int y){
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(x+i>=0&&x+i<n&&y+j>=0&&y+j<m&&a[x+i][y+j]=='@'){
                a[x+i][y+j]='*';
                dfs(x+i,y+j);
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        int num=0;
        if(n==0&&m==0)break;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]=='@'){
                    a[i][j]='*';
                    num++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
