#include <bits/stdc++.h>
#define N 1000007
using namespace std;
int q[10000000];
int vis[10000000];
int main()
{
    int n,m;
    int a,sum,num,p,pp;
    while(scanf("%d%d",&n,&m)!=EOF){
        sum=0;
        p=0;
        num=0;
        memset(q,0,sizeof(q));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(a%m==0){
                p=1;

            }

        }
        if(p==1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
