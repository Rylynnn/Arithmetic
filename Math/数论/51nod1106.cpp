#include <bits/stdc++.h>
#define N 100007
using namespace std;
int prime[N],check[N],tot;
void getprime(){
    memset(check,0,sizeof(check));
    tot=0;
    check[0]=check[1]=1;
    for(int i=2;i<N;i++){
        if(!check[i]){
            prime[tot++]=i;
        }
        for(int j=0;j<tot;j++){
            if(i*prime[j]>N){
                break;
            }
            check[i*prime[j]]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
int main()
{
    int n,a;
    getprime();
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            int p=0;
            for(int i=0;prime[i]*prime[i]<=a;i++){
                if(a%prime[i]==0){
                    p=1;
                    break;
                }
            }
            if(p==0){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
}
