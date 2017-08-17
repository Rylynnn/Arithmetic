/*************************************************************************
    > File Name: A.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年07月29日 星期六 18时05分33秒
 ************************************************************************/
#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
int t1, t2;
double amax, bmax, ans;
double sqr(double x){
    return x * x;
}
bool fequal(double a,double b)
{	return fabs(a-b)<eps;
}	
int fcmp(double x)
{	if (fabs(x)<eps)
		return 0;
	return x>0?1:-1;
}
struct point//点模板
{	double x,y;
	point(double x=0,double y=0):x(x),y(y) {}
	double length()
	{	return sqrt(x*x+y*y);
	}
}c, h, s;
point operator +(point a,point b)
{	return point(a.x+b.x,a.y+b.y);
}
point operator -(point a,point b)
{	return point(a.x-b.x,a.y-b.y);
}
point operator *(point a,double b)
{	return point(a.x*b,a.y*b);
}
point operator *(double b,point a)
{	return point(a.x*b,a.y*b);
}
point operator /(point a,double b)
{	return point(a.x/b,a.y/b);
}
bool operator <(point a,point b)
{	return a.x<b.x||(fcmp(a.x-b.x)==0&&a.y<b.y);
}
bool operator ==(point a,point b)
{	return (fcmp(a.x-b.x)==0&&fcmp(a.y-b.y)==0);
}
double dist(point a,point b)
{	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
double dist2(point a, point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool point_in_circle(point p,double r,point center)//center located at (0,0) as default
{	return fcmp(dist2(p,center)-r*r)<=0;
}
point normal(point x)
{	double l=x.length();
	return point(-x.y/l,x.x/l);
}

void circle_inter_point(point p1,double r1,point p2,double r2,vector<point>& v)//两圆相交求交点
{	double d=dist(p1,p2);
	if (fcmp(d-r1-r2)>0)
		return ;
	if (fcmp(d-r1-r2)==0)
	{	v.push_back((p2-p1)*r1/d+p1);
		return ;
	}
	if (r1<r2)
		swap(r1,r2),swap(p1,p2);
	if (fcmp(d-(r1-r2))<0)
		return ;
	if (fcmp(d-(r1-r2))==0)
	{	v.push_back((p2-p1)*r2/r1+p2);
		return ;
	}
	double c=(sqr(r1)+sqr(d)-sqr(r2))/(2*d);
	double h=sqrt(sqr(r1)-sqr(c));
	point p=p1+(p2-p1)*(c/d);
	v.push_back(p+normal(p-p1)*h);
	v.push_back(p-normal(p-p1)*h);
}

bool find_r(double r){
    int r1, r2, r3;
    double c0 = (double)0;
    r1 = max(c0, r);
    r2 = max(c0, amax - dist(s, h) - r);//A得先到商店
    r3 = max(c0, bmax - r);
    vector<point> v;
    v.clear();
    circle_inter_point(c, r1, s, r2, v);
    vector<point>::iterator it;
    for(it=v.begin(); it!=v.end(); it++){
        if(point_in_circle(h, r3, *it)){
            return true;
        }
    }
    v.clear();
    circle_inter_point(s, r2, h, r3, v);
    for(it=v.begin(); it!=v.end(); it++){
        if(point_in_circle(c, r1, *it)){
            return true;
        }
    }
    v.clear();
    circle_inter_point(h, r3, c, r1, v);
    for(it=v.begin(); it!=v.end(); it++){
        if(point_in_circle(s, r2, *it)){
            return true;
        }
    }
    return false;
}
double binary_s(double l, double r){
    while(eps < abs(r - l)){
        double mid = (r + l) / 2;
        if(find_r(mid)){//小于
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r;
}
int main()
{
    cin >> t1 >> t2 >> c.x >> c.y >> h.x >> h.y >> s.x >> s.y;
    amax = t1 + dist(c, s) + dist(s, h);
    bmax = t2 + dist(c, h);
    if(bmax >= amax - t1){
        ans = min(bmax, amax);
    }
    else{
        double l, r;
        l = 0;
        r = min(bmax, amax);
        ans = binary_s(l, r);
    }
    printf("%.8f", ans);
    return 0;
}
