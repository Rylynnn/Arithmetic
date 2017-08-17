const int MaxN=111;
const int INF=100000000;
int N,g[MaxN][MaxN];

void floyd()
{
	for (int k=1;k<=N;k++)
	  for (int i=1;i<=N;i++)
	    for (int j=1;j<=N;j++)
		  g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
} 
