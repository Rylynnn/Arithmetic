#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#define eps 1e-8
#define PI acos(-1)
using namespace std;
int main()
{
    int n,k;
    double l,nl,ang,ans,nn,m;
    while(scanf("%d%d",&n,&k)!=EOF){
        scanf("%lf",&l);
        nl=l;
        nn=nl;
        ans=nl/2.0;
        ang=(180.0*(double)(n-2))/(double)n;
        ang=ang*PI/180.0;
        //cout<<ang<<endl;
        //printf("%.3f",cos(ang));
        for(int i=0;i<=k;i++){
            ans+=(n-1)*nl+nn/2.0;
            nn=nl;
            m=(nl*nl)/2.0;
            nl=sqrt(m*(1.0-cos(ang)+eps));cout<<m<<' '<<nl<<' '<<ans<<endl;
        }

        printf("%.9f\n",ans);
    }
    return 0;
}
