#include <bits/stdc++.h>
#define N 100007
using namespace std;
long long a[N],ans;
int main()
{
    long long n,k,maxm,num,i;
    while(scanf("%I64d%I64d",&n,&k)!=EOF){
        memset(a,0,sizeof(a));
        maxm=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
        }
        num=n-k;
        maxm=a[n];
        for(i=1;i<=num;i++){
            ans=a[i]+a[num*2-i+1];
            maxm=max(maxm,ans);
        }
        cout<<maxm<<endl;
    }
    return 0;
}
