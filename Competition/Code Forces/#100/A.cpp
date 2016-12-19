#include <bits/stdc++.h>
#define Pi acos(-1)
#define eps 1e-6
using namespace std;
int main()
{
    int  r1,r2;
    double now,n,ang;
    while(scanf("%lf%d%d",&n,&r1,&r2)!=EOF){
        if(r1<r2){
            printf("NO\n");
            continue;
        }
        if(r1==r2){
            now=1;
            if(n==1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
            continue;
        }
        else{
            ang=(double)r2/(double)(r1-r2);
            if(fabs(1-fabs(ang))<=eps||(1-fabs(ang))>=eps){
                now=asin(ang);
                now=(2*Pi)/(2*now);
            }
            else{
                now=1;
            }
        }
        //cout<<now;
        if(fabs(now-n)<=eps||(now-n)>=eps){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
