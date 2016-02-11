#include <bits/stdc++.h>
using namespace std;
int d[3]={-1,0,1};
int m,n;
char a[107][107];
void dfs(int x,int y){
    int i,j,k,nx,ny;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            nx=x+d[i];
            ny=y+d[j];
            //cout<<nx<<' '<<ny<<endl;
            if(nx>=0&&ny>=0&&nx<m&&ny<n&&a[nx][ny]=='@'){//边界条件nx<m和ny<n写反了。。。。= =
                //cout<<1;
                a[nx][ny]='*';
                dfs(nx,ny);
            }
        }
    }
}
int main()
{
    int num,i,j;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(n==0&&m==0){
            break;
        }
        memset(a,0,sizeof(a));
        num=0;
        for(i=0;i<m;i++){
            scanf("%s",a[i]);
        }
        //printf("\n");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(a[i][j]=='@'){
                    a[i][j]='*';
                    //for(i=0;i<m;i++){
                        //printf("%s\n",a[i]);
                    //}
                    num++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
