/*************************************************************************
    > File Name: CF578C.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月02日 星期三 22时56分39秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define eps 1e-10
using namespace std;
int a[200007];
int n;
double aabs(double b){
    if(b < eps){
        return -b;
    }
    return b;
}
double get_max(double x){
    double maxm = (double)a[n-1] - x;
    double sum = (double)a[n-1] - x;
    for(int i=n-2; i>=0; i--){
        sum = max((double)a[i] - x, (double)a[i] - x + sum);
        maxm = max(sum, maxm);
    }
    return maxm;
}
double get_min(double x){
    double minm = (double)a[n-1] - x;
    double sum = (double)a[n-1] - x;
    for(int i=n-2; i>=0; i--){
        sum = min((double)a[i] - x, (double)a[i] - x + sum);
        minm = min(sum, minm);
    }
    return minm;
}

int main()
{
    scanf("%d", &n);
    double L, R;
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        L = min(L, (double)a[i]);
        R = max(R, (double)a[i]);
    }
    while(R - L > eps){
        double x1 = L + (R - L) / 3;
        double x2 = L + (R - L) / 3 * 2;
        double ans1 = max(aabs(get_min(x1)), aabs(get_max(x1)));         
        double ans2 = max(aabs(get_min(x2)), aabs(get_max(x2)));
        if(ans1 < ans2){
            R = x2;
        }
        else if(ans1 >= ans2){
            L = x1;      
        }
    }
    double ans = max(aabs(get_min(L)), aabs(get_max(R)));
    printf("%.10lf\n", ans);
    return 0;
}
