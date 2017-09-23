/*************************************************************************
    > File Name: Simpson.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 二  9/19 01:01:53 2017
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std; 
  
const double eps = 1e-6;  //积分精度  
  
double a, b, l, r;  
// simpson公式用到的函数  
double F (double x){//也就是被积函数,本题是椭圆  
     return sqrt(b * b * (1 - x * x / (a * a)));  
}  
  
// 三点simpson法. 这里要求F是一个全局函数  
double simpson (double a, double b){  
    double c =  a + (b - a) / 2;  
    return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6;  
}  
// 自适应Simpson公式（递归过程）。已知整个区间[a,b]上的三点simpson值A  
double asr(double a, double b, double eps, double A){  
    double c = a + (b - a) / 2;  
    double L = simpson(a, c), R = simpson(c, b);  
    if (fabs(A - L - R) <= 15 * eps) return L + R + (A - L - R) / 15;  
    return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);  
}  
// 自适应Simpson公式（主过程）    
double asr(double a, double b, double eps) {    
    return asr(a, b, eps, simpson(a, b));    
}  
  
int main ()  
{  
    int T;  
    scanf("%d",&T);  
    while (T--)  
    {  
        scanf("%lf%lf%lf%lf",&a,&b,&l,&r);  
        double ans = asr(l,r,eps);  
        ans *= 2;//积分只计算了x轴上半部分  
        printf("%.3f\n",ans);  
    }  
    return 0;  
}  
