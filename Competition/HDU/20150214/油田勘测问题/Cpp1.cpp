#include<stdio.h>
#include<string.h>
const int maxn=100+10;
char land[maxn][maxn];
int m,n,t,vis[maxn][maxn];
bool can;
void dfs(int i,int j,int num)//”√DFS µœ÷
{
	if(i<0||i>=m||j<0||j>=n){
        return;
	}
	if(land[i][j]=='D'&&num<=t){
        can=true;
        return;
	}
	if(vis[i][j]>0||land[i][j]=='X') return;
	vis[i][j]=num;
	for(int dx=-1;dx<=1;dx++)
		for(int dy=-1;dy<=1;dy++)
			if(dx!=0||dy!=0) dfs(i+dx,j+dy,++vis[i][j]);
}
int main()
{
	while(scanf("%d%d%d",&m,&n,&t)==3&&n&&m&&t){
		int i,j;
		memset(land,0,sizeof(land));
		for(i=0;i<m;i++){
            scanf("%s",land[i]);
		}
        memset(vis,0,sizeof(vis));
		can=false;
		for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(land[i][j]=='s'){
                    break;
                }
            }
		}
		int num=0;
		dfs(i,j,num);
		if(can){
            printf("Yes\n");
		}
		else{
            printf("No\n");
		}

		/*
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
				printf("%d",vis[i][j]);
			printf("\n");
		}
		*/

	}
	return 0;
}
