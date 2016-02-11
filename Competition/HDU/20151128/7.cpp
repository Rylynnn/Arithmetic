#include <bits/stdc++.h>
#define N 10007
using namespace std;
int par[10007];
int ans[10007];
int findpar(int x) {
    if(par[x]==x) {
        return par[x];
    }
    else return par[x]=findpar(par[x]);
}
int main()
{
    int n,m,p,x,y,maxm;
    long long num;
    while(scanf("%d%d",&n,&m)!=EOF) {
        memset(par,0,sizeof(par));
        memset(ans,0,sizeof(ans));
        int k=0;
        for(int i=1;i<=n;i++){
            cin>>num;
            par[i]=i;
            if((sqrt(5*num*num+4)==(int)(sqrt(5*num*num+4))||sqrt(5*num*num-4)==(int)(sqrt(5*num*num-4)))){
                ans[i]=1;
            }
        }
        for (int i=1;i<=m;i++){
			cin>>x>>y;
			int fx=findpar(x);
			int fy=findpar(y);
			if (fx!=fy){
				par[fx]=fy;
				ans[fy]=ans[fx]+ans[fy];
			}
		}
		maxm=0;
        for (int i=1;i<=n;i++){
			maxm=max(ans[i],maxm);
		}
        cout<<maxm<<endl;
    }
    return 0;
}
