#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int vis[1000007],num;
int pri[1000007];
void prime(int n){
    memset(vis,0,sizeof(vis));
    for(int i=2;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            pri[num++]=i;
            for(int j=2;j<=n/i;j++){
                vis[i*j]=1;
            }
        }
    }
}
int main()
{
    int t;
    ll ans,g,l;
    num=0;
    prime(1000000);
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%I64d%I64d",&g,&l);
            if(l%g!=0){
                printf("0\n");
            }
            else{
                ans=1;
                ll d=l/g;
                for(int i=0;i<num;i++){
                    if(d%pri[i]==0){
                        ll n=0;
                        while(d%pri[i]==0){
                            n++;
                            d/=pri[i];
                        }
                        ans*=6*n;
                    }
                }
                if(d>1){
                    ans*=6;
                }
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}
