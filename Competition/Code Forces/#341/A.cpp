#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    long long  n,i,a,minm;
    long long sum,num;
    while(scanf("%I64d",&n)!=EOF){
        sum=0;
        int minm=INF;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a);
            if(a&1){
                if(minm>a)
                minm=a;
            }
            sum+=a;
        }
        if(sum&1){
            sum-=minm;
            printf("%I64d\n",sum);
        }
        else{
            printf("%I64d\n",sum);
        }
    }
    return 0;
}
