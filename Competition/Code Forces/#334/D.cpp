#include <bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
int main()
{
    long long p,k,temp,ans,num;
    while(scanf("%I64d%I64d",&p,&k)!=EOF){
        if(k==0){
            num=p-1;
        }
        else if(k==1){
            num=p;
        }
        else{
            int i;
            int temp;
            temp=k;
            for(i=1;;i++){
                if(temp==1){
                    break;
                }
                else{
                    temp=(temp*k)%p;
                }
            }
            num=(p-1)/i;
        }
        ans=1;
        for(int i=0;i<num;i++){
            ans=(ans*p)%MOD;
        }
        printf("%I64d\n",ans);
    }
}
