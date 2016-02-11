#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n,k,i,j;
	int v[30010],w[30010],dp[30010];
	scanf("%d%d",&n,&k);
	memset(dp,0,sizeof(dp));
	for(i=1;i<=k;i++){
		scanf("%d%d",&v[i],&w[i]);
	}
	for(i=1;i<=k;i++){
		for(j=n;j>=v[i];j--){
			dp[j]=max(dp[j-v[i]]+v[i]*w[i],dp[j]);
		}
	}
	printf("%d\n",dp[n]);
}