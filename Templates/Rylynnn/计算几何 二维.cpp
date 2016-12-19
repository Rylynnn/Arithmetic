#include <bits/stdc++.h>
#define MaX 500008
#define ll long long
using namespace std;
const double eps=1e-10;
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
//向量加减
Vector operator + (Vector a,Vector b){
    return Vector(a.x+b.x,a.y+b.y);
}
Vector operator - (Vector a,Vector b){
    return Vector(a.x-b.x,a.y-b.y);
}
//向量乘除数值
Vector operator * (Vector a,double b){
    return Vector(a.x*b,a.y*b);
}
Vector operator / (Vector a,double b){
    return Vector(a.x/b,a.y/b);
}
//eps控制，重载<和==
int dcmp(double x){
    if(fabs(x)<eps){
        return 0;
    }
    else{
        return x<0?-1:1;
    }
}
bool operator <(const Point& a,const Point& b){
    return a.x-b.x<eps||(dcmp(a.x-b.x)==0&&a.y-b.y<eps);
}
bool  operator == (const Point& a,const Point& b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
//计算a的极角
double AngleX(Vector a){
    return atan2(a.y,a.x);
}
//向量点乘
double Dot(Vector a,Vector b){
    return a.x*b.x+a.y*b.y;
}
//向量a的模
double Length(Vector a){
    return (sqrt(Dot(a,a)));
}
//两个向量的夹角
double Angle(Vector a,Vector b){
    return acos(Dot(a,b)/Length(a)/Length(b));
}
//向量叉乘
double Cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}
//三点组成的面积
double Area2(Point a,Point b,Point c){
    return Cross(b-a,c-a);
}
//将向量a旋转rad度，rad是弧度
Vector Rotate(Vector a,double rad){
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
//计算向量的单位法向量，先判a不是零向量
Vector Normal(Vector a){
    double L=Length(a);
    return Vector(-a.y/L,a.x/L);
}
//计算两个直线交点，直线方程为p+tv，q+tw，先判Cross(v,w)!=0
Point GetLineInter(Point p,Vector v,Point q,Vector w){
    Vector u=p-q;
    double t=Cross(w,u)/Cross(v,w);
    return p+v*t;
}
//点p到直线ab的距离
double DisToL(Point p,Point a,Point b){
    Vector v1=b-a,v2=p-a;
    return fabs(Cross(v1,v2))/Length(v1);//不取绝对值为有向距离
}
//点p到线段ab的距离
double DisToS(Point p,Point a,Point b){
    if(a==b){
        return Length(p-a);
    }
    Vector v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2)<0)){
        return Length(v2);
    }
    else if(dcmp(Dot(v1,v3))>0){
        return Length(v3);
    }
    else{
        return fabs(Cross(v1,v2))/Length(v1);
    }
}
//点p在直线ab上的投影
Point GetLineProj(Point p,Point a,Point b){
    Vector v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}
//线段ab,cd相交判定（交点不能为两个端点）
bool segProInter(Point a,Point b,Point c,Point d){
    double p1=Cross(b-a,c-a),p2=Cross(b-a,d-a),
           p3=Cross(d-c,a-c),p4=Cross(d-c,b-c);
    return dcmp(p1)*dcmp(p2)<0&&dcmp(p3)*dcmp(p4)<0;
}
//如果相交允许为端点，直接判一下是否有端点在另一条直线上
bool OnSeg(Point p,Point a,Point b){
    return dcmp(Cross(a-p,b-p))==0&&dcmp(Dot(a-p,b-p))<0;
}
int main()
{
}
