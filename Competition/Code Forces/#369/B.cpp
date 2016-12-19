#include <bits/stdc++.h>
#define MaX 500008
#define ll long long
using namespace std;
ll n,x,y;
ll a[507][507],sum[507];
int main()
{
    while(scanf("%I64d",&n)!=EOF){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                scanf("%I64d",&a[i][j]);
                if(a[i][j]==0){
                    x=i;
                    y=j;
                }
            }
        }
        if(n==1){
            printf("1\n");
            continue;
        }
        ll p=0;
        memset(sum,0,sizeof(sum));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                sum[i]+=a[i][j];
            }
        }
        ll now;
        for(ll i=0;i<n;i++){
            if(i!=x){
                now=sum[i];
                break;
            }
        }
        for(ll i=0;i<n;i++){
            if(i!=x&&sum[i]!=now){
                p=1;
            }
        }
        if(p==0){
            a[x][y]=now-sum[x];
            memset(sum,0,sizeof(sum));
            for(ll i=0;i<n;i++){
                for(ll j=0;j<n;j++){
                    sum[i]+=a[j][i];
                }
            }
            for(ll i=0;i<n;i++){
                if(sum[i]!=sum[0]){
                    p=1;
                }
            }
            ll one=0,two=0;
            for(ll i=0;i<n;i++){
                one+=a[i][i];
                two+=a[i][n-i-1];
            }
            if(one!=two){
                p=1;
            }
        }
        if(p==1||a[x][y]<=0){
            printf("-1\n");
        }
        else{
            printf("%I64d\n",a[x][y]);
        }
    }
}
