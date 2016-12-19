#include <bits/stdc++.h>
using namespace std;
long long a[100007];
int main()
{
    long long n,h,k,ans,now,p;
    while(scanf("%I64d%I64d%I64d",&n,&h,&k)!=EOF){
        now=ans=0;
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            scanf("%I64d",&a[i]);
        }
        for(int j=0;j<n;j++){
            //cout<<now<<endl;
            if(now+a[j]>h){
                p=now+a[j]-h;
                if(p%k==0){
                    ans+=p/k;
                    now-=(p/k)*k;
                }
                else{
                    ans+=p/k+1;
                    now-=(p/k+1)*k;
                }//cout<<ans<<endl;
                if(now<0){
                    now=0;
                }
            }
            now+=a[j];

        }
        if(now>0){
            if(now%k==0){
                ans+=now/k;
            }
            else{
                ans+=now/k+1;
            }//
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
