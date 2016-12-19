#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a;
    while(scanf("%I64d",&a)!=EOF){
        if(a%1234567==0){
            printf("YES\n");
        }
        else if(a%123456==0){
            printf("YES\n");
        }
        else if(a%1234==0){
            printf("YES\n");
        }
        else{
            ll na,nb,nc;
            na=a/1234567;
            //cout<<na;
            ll p=0;
            for(ll i=na;i>=0;i--){
                if(p==1){
                    break;
                }
                ll now;
                now=a-i*1234567;
                nb=now/123456;
                //cout<<now<<' ';
                for(ll j=nb;j>=0;j--){
                    if(p==1){
                        break;
                    }
                    if(now-j*123456==0){
                        p=1;
                        break;
                    }
                    else{
                        ll nnow;
                        nnow=now-j*123456;
                        nc=nnow/1234; //cout<<nnow<<' ';
                        for(ll k=nc;k>=0;k--){
                            if(nnow-k*1234==0){
                                //cout<<k<<' ';
                                p=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(p==1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }

}
