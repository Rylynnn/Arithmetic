#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#define eps 1e-8
#define PI acos(-1)
using namespace std;
double s(const double r) {
    return PI*r*r;
}
double l1,l2,ang,len;
int main() {
    while(3==scanf("%lf%lf%lf",&l1,&l2,&ang)) {
        if(ang+eps<0) {
            ang=-ang;
            swap(l1,l2);
        }
        while(ang-eps>360) {
            ang-=360;
        }
        if(ang-eps>180) {
            ang=360-ang;
            swap(l1,l2);
        }
        ang=90.0;
        ang=ang*PI/180;
        cout<<ang<<endl;
        len=sqrt(l1*l1+l2*l2-2.0*l1*l2*cos(ang))/2.0;
        //cout<<len;
        if(len<abs(l1-l2)/2.0+eps) {
            printf("%.8f\n",s(max(l1,l2)/2.0));
        }
        else {
            printf("%.8f\n",s(((l1+l2)/2.0+len)/2.0));
        }
    }
    return 0;
}
