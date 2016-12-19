#include <bits/stdc++.h>
#define N 100007
#define ll long long
using namespace std;
ll prime[N],vis[N],tot;
void getprime(){
    tot=0;
    memset(vis,0,sizeof(vis));
    vis[0]=vis[1]=1;
    for(ll i=2;i<N;i++){
        if(!vis[i]){
            prime[tot++]=i;
        }
        for(ll j=0;j<tot;j++){
            if(i*prime[j]>N){//i*prime[j]¿ÉÄÜ³¬ll
                break;
            }
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
ll pow_mod(ll a,ll b,ll mod){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int main()
{
    int p,phi,tmp;
    getprime();
    scanf("%d",&p);
    if(p==2){
        printf("1\n");
        return 0;
    }
    if(p==3){
        printf("2\n");
        return 0;
    }
    for(int i=2;i<=p-1;i++){
        tmp=0;
        for(int j=0;j<=tot&&prime[j]*prime[j]<=p-1;j++){
            if((p-1)%prime[j]==0){
                int now=(p-1)/prime[j];
                if(pow_mod((long long)i,(long long)now,(long long)p)==1LL){
                    tmp=1;
                    break;
                }
            }
        }
        if(tmp==0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
