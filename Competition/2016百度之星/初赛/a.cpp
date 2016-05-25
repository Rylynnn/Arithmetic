#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;
int main()
{
    int t,n;
    ll x,m,k,c,a[10007],len,be,p,ans;
    while(scanf("%d",&t)!=EOF){
        n=0;
        while(n++<t){
            scanf("%I64d%I64d%I64d%I64d",&x,&m,&k,&c);
            a[1]=x%k;
            p=0;
            printf("Case #%d:\n",n);
            for(int i=2;i<10007;i++){
                a[i]=(a[i-1]*10+x)%k;
                for(int j=1;j<i;j++){
                    if(a[i]==a[j]){
                        len=i-j;
                        be=j;
                        p=1;
                    }
                }
                if(p==1){
                    break;
                }
            }
            ans=(m-be)%len+be;
            //cout<<be<<' '<<len<<' '<<ans<<endl;
            if(a[ans]==c){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}
