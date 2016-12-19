#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
int main()
{
    ll x0,y0,z0,x1,x2,y1,y2,z1,z2,x,y,z;
    while(scanf("%lld%lld%lld",&x0,&y0,&z0)!=EOF){
        scanf("%lld%lld%lld",&x1,&y1,&z1);
        scanf("%lld%lld%lld",&x2,&y2,&z2);
        if(x1<=x0&&x0<=x2&&y1<=y0&&y0<=y2&&z1<=z0&&z0<=z2){
            printf("0\n");
            continue;
        }
        else{
            if(x1<=x0&&x0<=x2&&!(y1<=y0&&y0<=y2)&&!(z1<=z0&&z0<=z2)){
                if(y0<y1){
                    y=y1;
                }
                else{
                    y=y2;
                }
                if(z0<z1){
                    z=z1;
                }
                else{
                    z=z2;
                }
                printf("%lld\n",   ((z-z0) * (z-z0) + (y-y0) * (y-y0)));
            }
            else if(!(x1<=x0&&x0<=x2)&&y1<=y0&&y0<=y2&&!(z1<=z0&&z0<=z2)){
                if(x0<x1){
                    x=x1;
                }
                else{
                    x=x2;
                }
                if(z0<z1){
                    z=z1;
                }
                else{
                    z=z2;
                }
                printf("%lld\n",   ((z-z0) * (z-z0) + (x-x0) * (x-x0)));
            }
            else if(!(x1<=x0&&x0<=x2)&&!(y1<=y0&&y0<=y2)&&z1<=z0&&z0<=z2){
                if(y0<y1){
                    y=y1;
                }
                else{
                    y=y2;
                }
                if(x0<x1){
                    x=x1;
                }
                else{
                    x=x2;
                }
                printf("%lld\n",   ((x-x0) * (x-x0) + (y-y0) * (y-y0)));
            }
            else if((x1<=x0&&x0<=x2)&&(y1<=y0&&y0<=y2)&&!(z1<=z0&&z0<=z2)){
                if(z0<z1){
                    z=z1;
                }
                else{
                    z=z2;
                }
                printf("%lld\n", (z-z0)*(z-z0));
            }
            else if((x1<=x0&&x0<=x2)&&!(y1<=y0&&y0<=y2)&&(z1<=z0&&z0<=z2)){
                if(y0<y1){
                    y=y1;
                }
                else{
                    y=y2;
                }
                printf("%lld\n", (y-y0)*(y-y0));
            }
            else if(!(x1<=x0&&x0<=x2)&&(y1<=y0&&y0<=y2)&&z1<=z0&&z0<=z2){
                if(x0<x1){
                    x=x1;
                }
                else{
                    x=x2;
                }
                printf("%lld\n",  (x-x0)*(x-x0));
            }
            else{
                if(x0<x1){
                    x=x1;
                }
                else{
                    x=x2;
                }
                if(y0<y1){
                    y=y1;
                }
                else{
                    y=y2;
                }
                if(z0<z1){
                    z=z1;
                }
                else{
                    z=z2;
                }
                printf("%lld\n",((x-x0) * (x-x0) + (y-y0) * (y-y0)+(z-z0)*(z-z0)));
            }
        }
    }
}
