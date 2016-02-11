/*
wa1：没考虑区间边界处理
wa2：没考虑区间左边界大于右边界情况
wa3：处理wa2的时候。。交换变量用的是t。。。。。。。orz。。。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int t,n,a,b,num;
	int i,j;
	int p[410];
	while(scanf("%d",&t)!=EOF){
		while(t--){
			memset(p,0,sizeof(p));
			scanf("%d",&n);
			for(i=1;i<=n;i++){
				scanf("%d%d",&a,&b);
				if(a>b){
					num=a,a=b,b=num;
				}
				if(!(a&1)){
					a--;
				}
				if(b&1){
					b++;
				}
				for(j=a;j<=b;j++){
					p[j]++;
				}
			}
			int maxm=-0xfffffff;
			for(i=1;i<=400;i++){
				maxm=max(p[i],maxm);
			}
			printf("%d\n",maxm*10);
		}
	}
	return 0;
}
