#include <bits/stdc++.h>
using namespace std;
int m,n;
string a[107];
void dfs(int i,int j){
    int ni,nj;
    for(int p=-1;p<=1;p++){
        for(int q=-1;q<=1;q++){
            ni=i+p;
            nj=j+q;
            if(ni>=0&&ni<m&&nj>=0&&nj<n){
                if(a[ni][nj]=='@'){
                    a[ni][nj]='*';
                    dfs(ni,nj);
                }
            }
        }
    }
}
int main()
{
    int num;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m==0||n==0){
            break;
        }
        for(int i=0;i<m;i++){
                cin>>a[i];
        }
        num=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='@'){
                    a[i][j]='*';
                    dfs(i,j);
                    num++;
                }
            }
        }
        printf("%d\n",num);
    }
    return 0;
}
