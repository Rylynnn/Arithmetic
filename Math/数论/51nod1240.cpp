#include <bits/stdc++.h>
#define N 100007
using namespace std;
int prime[N+7],check[N+7],tot;
void getprime(){
    memset(check,0,sizeof(check));
    check[0]=check[1]=1,tot=0;
    for(int i=2;i<=N;i++){
        if(!check[i]){
            prime[tot++]=i;
        }
        for(int j=0;j<tot&&prime[j]*i<=N;j++){
            check[prime[j]*i]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}
int main()
{
    int n,num,k,p;
    getprime();
    while(scanf("%d",&n)!=EOF){
        p=0,k=0;
        int now=n;
        for(int i=0;i<tot&&prime[i]*prime[i]<=now;i++){
            if(n%prime[i]==0){
                num=0;
                while(n%prime[i]==0){
                    n/=prime[i];
                    num++;
                }
                if(num<2){
                    k++;
                }
                else{
                    p=1;
                }
            }
        }
        if(n>1){//如果最后未除尽，则一定剩一个大于√n的素因子（可能为n也可能小于n）
            k++;
        }
        if(p==1){
            printf("0\n");
        }
        else{
            if(k%2==1){
                printf("-1\n");
            }
            else{
                printf("1\n");
            }
        }
    }
    return 0;
}
