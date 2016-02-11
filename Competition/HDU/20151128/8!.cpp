#include <bits/stdc++.h>
#define N 10007
using namespace std;
int a[110000];
int main()
{
	int t,n,m,k,p,i;
	scanf("%d",&t);
	while (t--){
		 scanf("%d%d%d",&n,&m,&k);
		 int ans=0;
		 for (i=1;i<=n;i++){
		   scanf("%d",&a[i]);
		 }
		 for ( i=1;i<=m;i++){
			scanf("%d",&p);
			if (k>=0) k-=(a[p]);
			a[p]=0x3f3f3f3f;

		}
		ans=m;
		if (k<0){
            printf("-1\n");
		}
		else{
			sort(a+1,a+n+1);
			for (i=1;i<=n;i++){
				if (k>=a[i]){
					ans++;
					k-=a[i];
				}
				else{
                    break;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
