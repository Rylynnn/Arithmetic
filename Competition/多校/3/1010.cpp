#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a,v1,v2,v,t;
    while(scanf("%lf%lf%lf",&a,&v1,&v2)!=EOF){
        if(a==0){
            printf("0.0000000000\n");
            continue;
        }
        if(v1<=v2){
            printf("Infinity\n");
        }
        else{
            v=a*v1;
            t=(v1*v1)-(v2*v2);
            printf("%.10lf\n",v/t);
        }
    }
}

