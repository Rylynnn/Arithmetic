#include <bits/stdc++.h>
#define N 550005
using namespace std;
int pri[N];
bool vis[N];
int num;
int n;
void Prime(){
	memset(vis,true,sizeof(vis));
	memset(pri,0,sizeof(pri));
	n=10000;
	num=0;
	int i,j;
	for (i=2;i<=n;i++){
		if (vis[i]){
			num++;
			pri[num]=i;
			for (j=2;j<=n/i;j++)
                vis[i*j]=0;
		}
	}
}
int main()
{
    Prime();
    int i;
    long long minm,ans;
    int t,p;
    scanf("%d",&t);{
        while(t--){
            scanf("%d",&p);
            minm=100000000;
            ans=0;
            for(i=1;i<=num;i++){
                if(abs(pri[i]*pri[i]-p)<minm){
                    minm=abs(pri[i]*pri[i]-p);
                    ans=pri[i]*pri[i];
                }
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
