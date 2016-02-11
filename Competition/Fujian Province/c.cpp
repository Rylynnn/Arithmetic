#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n,i;
    double m;
    double x1,x2,x3,y1,y2,y3,k1,k2,k3,d1,d2,d3,p1,p2,p3;
    double high[3];
    while(scanf("%d",&n)!=EOF){
        while(n--){
            scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3);
            k1=(y2-y3)/(x2-x3);
            d1=y2-k1*x2;
            p1=k1*x1-y1+d1;
            if(p1<0)p1=-p1;
            high[0]=p1/(sqrt(k1*k1+1));
            printf("%f %f %f %f\n",k1,d1,p1,high[0]);
            k2=(y1-y3)/(x1-x3);
            d2=y1-k2*x1;
            p2=k2*x2-y2+d2;
            if(p2<0)p2=-p2;
            high[1]=p2/(sqrt(k2*k2+1));
            printf("%f %f %f %f\n",k2,d2,p2,high[1]);
            k3=(y1-y2)/(x1-x2);
            d3=y1-k3*x1;
            p3=k3*x3-y3+d3;
            if(p1<0)p1=-p1;
            high[2]=p1/(sqrt(k3*k3+1));
            printf("%f %f %f %f\n",k3,d3,p3,high[2]);
            for(i=0;i<3;i++){
                if(high[i]!=0){
                    m=high[i];
            }
            for(i=0;i<3;i++){
                if(high[i]<m)m=high[i];
            }
            printf("%.4f",m);
        }
    }
    return 0;
}
