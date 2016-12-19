#include <bits/stdc++.h>
#define N 1000007
using namespace std;
int check[N],prime[N],pprime[N],tot,num;
void getprime()
{
    memset(check,0,sizeof(check));
    check[0]=check[1]=1;
    tot=1;
    for(int i=2;i<=N;i++){
        if(!check[i]){
            prime[tot++]=i;
        }
        for(int j=1;j<=tot;j++){
            if(prime[j]*i>N){
                break;
            }
            check[prime[j]*i]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    num=0;
    for(int i=1;i<=tot;i++){
        if(!check[i]){
            pprime[num++]=prime[i];
        }
    }
}
int main()
{
    int n,ans;
    getprime();
    while(scanf("%d",&n)!=EOF){
        ans=*lower_bound(pprime,pprime+num,n);
        printf("%d\n",ans);
    }
}
