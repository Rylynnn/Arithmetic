#include <bits/stdc++.h>
#define ll long long
#define N 1e18
using namespace std;
int main()
{
    double px,py,vx,vy,a,b,c,d,x1,x2,x3,x4,x5,x6,x7,y1,y2,y3,y4,y5,y6,y7;
    cin>>px>>py>>vx>>vy>>a>>b>>c>>d;
    double ay,ax;
    ax=vx/sqrt(vx*vx+vy*vy);
    ay=vy/sqrt(vx*vx+vy*vy);
    x1=px+b*ax;
    y1=py+b*ay;
    printf("%.10f %.10f\n",x1,y1);
    x2=px-c/2.0*ay;
    y2=py+c/2.0*ax;
    x3=px-a/2.0*ay;
    y3=py+a/2.0*ax;
    printf("%.10f %.10f\n",x3,y3);
    printf("%.10f %.10f\n",x2,y2);
    x4=x2-d*ax;
    y4=y2-d*ay;
    printf("%.10f %.10f\n",x4,y4);
    x5=2*px-x2;
    y5=2*py-y2;
    x6=x5-d*ax;
    y6=y5-d*ay;
    printf("%.10f %.10f\n",x6,y6);
    printf("%.10f %.10f\n",x5,y5);
    x7=2*px-x3;
    y7=2*py-y3;
    printf("%.10f %.10f\n",x7,y7);
    return 0;

}
