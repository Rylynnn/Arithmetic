#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>

const int MAXN=111;
using namespace std;

stack<int>S;
int edge[MAXN][MAXN];
int n,m;

void dfs(int x)
{
    S.push(x);
    for(int i=1;i<=n;i++)
	{
        if(edge[x][i]>0)
		{
            edge[i][x]=edge[x][i]=0;
            dfs(i);
            break;
        }
    }
}


void Fleury(int x){
    S.push(x);
    while(!S.empty()){
        int b=0;
        for(int i=1;i<=n;i++){
            if(edge[S.top()][i]>0){
                b=1;
                break;
            }
        }
        if(b==0){
            printf("%d",S.top());
            S.pop();
        }else {
            int y=S.top();
            S.pop();
            dfs(y);
        }
    }
    printf("\n");
}

int main(){
    scanf("%d%d",&n,&m); 
    memset(edge,0,sizeof(edge));
    int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        edge[x][y]=edge[y][x]=1;
    }
    int num=0,start=1;
    for(int i=1;i<=n;i++){                     
        int degree=0;
        for(int j=1;j<=n;j++){
            degree+=edge[i][j];
        }
        if(degree&1){
            start=i,num++;
        }
    }
    if(num==0||num==2){
        Fleury(start);
    }else
        printf("No Euler Path\n");
    return 0;
}
