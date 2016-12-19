/*
打表发现当n为合数的时候，1~n之间与n的最大公约数是对称的
发现这个不通，然后写一写公式发现其实是求phi（n/d）d是n的因子
*/
#include <bits/stdc++.h>
using namespace std;
int phi(int n){
    int temp=n;
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            temp=temp/i*(i-1);
        }
        if(n<i+1){
            break;
        }
    }
    if(n>1){
        temp=temp/n*(n-1);
    }
    return temp;
}
int main()
{
    int n,ans;
    while(scanf("%d",&n)!=EOF){
        ans=phi(n);
        int tmp=n;
        //printf("%d",ans);
        for(int i=2;i*i<=tmp;i++){
            if(n%i==0){
                while(n%i==0){
                    n/=i;
                }
                ans+=phi(tmp/i)*i;
            }
        }
        if(n>1){
            ans+=phi(tmp/n)*n;
            if(n!=tmp){
                ans+=tmp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
