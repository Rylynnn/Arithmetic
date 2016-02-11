#include<cstdio>
#include<algorithm>
#include<cmath>
#define eps 1e-8
using namespace std;
int main()
{
    double r,x,y,x1,y1;
    scanf("%lf%lf%lf%lf%lf",&r,&x,&y,&x1,&y1);
    double d=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    double m=d/(2.0*r);
    int n=m;
    if(d-n*(2.0*r)>eps){
        n++;
    }
    printf("%d",n);
}
