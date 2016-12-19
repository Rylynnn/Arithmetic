#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cmath>
#define INF 0x3f3f3f3f
#define MAX 207
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define MAX_POINT_NUM 0
using namespace std;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x; y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x, y - b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
};
//计算多边形面积
double CalcArea(Point p[],int n)
{
    double res = 0;
    for(int i = 0;i < n;i++)
        res += (p[i]^p[(i+1)%n]);
    return fabs(res/2);
}
//通过两点，确定直线方程
void Get_equation(Point p1,Point p2,double &a,double &b,double &c)
{
    a = p2.y - p1.y;
    b = p1.x - p2.x;
    c = p2.x*p1.y - p1.x*p2.y;
}
//求交点
Point Intersection(Point p1,Point p2,double a,double b,double c)
{
    double u = fabs(a*p1.x + b*p1.y + c);
    double v = fabs(a*p2.x + b*p2.y + c);
    Point t;
    t.x = (p1.x*v + p2.x*u)/(u+v);
    t.y = (p1.y*v + p2.y*u)/(u+v);
    return t;
}
Point tp[110];
void Cut(double a,double b,double c,Point p[],int &cnt)
{
    int tmp = 0;
    for(int i = 1;i <= cnt;i++)
    {
        //当前点在左侧，逆时针的点
        if(a*p[i].x + b*p[i].y + c < eps)tp[++tmp] = p[i];
        else
        {
            if(a*p[i-1].x + b*p[i-1].y + c < -eps)
                tp[++tmp] = Intersection(p[i-1],p[i],a,b,c);
            if(a*p[i+1].x + b*p[i+1].y + c < -eps)
                tp[++tmp] = Intersection(p[i],p[i+1],a,b,c);
        }
    }
    for(int i = 1;i <= tmp;i++)
        p[i] = tp[i];
    p[0] = p[tmp];
    p[tmp+1] = p[1];
    cnt = tmp;
}
double V[110],U[110],W[110];
int n;
Point p[110];
bool solve(int id)
{
    p[1] = Point(0,0);
    p[2] = Point(INF,0);
    p[3] = Point(INF,INF);
    p[4] = Point(0,INF);
    p[0] = p[4];
    p[5] = p[1];
    int cnt = 4;
    for(int i = 0;i < n;i++)
        if(i != id)
        {
            double a = (V[i] - V[id])/(V[i]*V[id]);
            double b = (U[i] - U[id])/(U[i]*U[id]);
            double c = (W[i] - W[id])/(W[i]*W[id]);
            if(sgn(a) == 0 && sgn(b) == 0)
            {
                if(sgn(c) >= 0)return false;
                else continue;
            }
            Cut(a,b,c,p,cnt);
        }
    if(sgn(CalcArea(p,cnt)) == 0)return false;
    else return true;
}
int main()
{
    while(scanf("%d",&n) == 1)
    {
        for(int i = 0;i < n;i++)
            scanf("%lf%lf%lf",&V[i],&U[i],&W[i]);
        for(int i = 0;i < n;i++)
        {
            if(solve(i))printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
