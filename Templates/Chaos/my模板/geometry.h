bool fequal(double a,double b)
{	return fabs(a-b)<prec;
}	
int fcmp(double x)
{	if (fabs(x)<prec)
		return 0;
	return x>0?1:-1;
}
struct point
{	double x,y;
	point(double x=0,double y=0):x(x),y(y) {}
	double length()
	{	return sqrt(x*x+y*y);
	}
};
struct line
{	point p1,p2;
	double a,b,c;
	double ang;
	line() {} 
	line(point px,point py)
	{	a=py.y-px.y;
 		b=px.x-py.x;
 		c=-a*px.x-b*px.y;
 		p1=px,p2=py;
 		point v=p2-p1;
		ang=atan2(v.y,v.x);
	}
	void angle()
	{	point px=p2-p1;
		ang=atan2(px.y,px.x);
	}
	point vec()
	{	return p2-p1;
	}
};
struct polygon
{	vector<point> pt;
	vector<line> li;
	double ar;
	double area();
	void getline();
	polygon()
	{	pt.clear();
		li.clear();
		ar=0;
	}
};
/* Operators */
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
bool operator <(line a,line b)
{	return a.angle()<b.angle();
}
/* Common operations */
point normal(point x)
{	double l=x.length();
	return point(-x.y/l,x.x/l);
}
double cp(point a,point b)
{	return a.x*b.y-a.y*b.x;
}
double dp(point a,point b)
{	return a.x*b.x+a.y*b.y;
}
double dist2(point a,point b)
{	return sqr(a.x-b.x)+sqr(a.y-b.y);
}
double dist(point a,point b)
{	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
double torad(double ang)//degree to radian
{	return pi*(ang/180);
}
point rotate(point a,double rad)
{	return point(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
point project(point& p,point &a,point &b)//Projection of p on line ab
{	vector v=b-a;
	return a+v*(dp(v,p-a)/dp(v,v));
}
polygon make_polygon(point p[],int n)
{	polygon poly;
	int i;
	for (i=1;i<=n;++i)
		poly.pt.push_back(p[i]);
	poly.getline();
	return poly;
}
double polygon::area()
{	int i;
	double area=0;
	for (i=1;i<pt.size();++i)
		area+=cp(pt[i-1],pt[i]);
	area+=cp(pt[i-1],pt[0]);
	ar=area;
	return area/2;
}
void polygon::getline()
{	int i;
	for (i=1;i<pt.size();++i)
		li.push_back(line(pt[i-1],pt[i]));
	li.push_back(line(pt[pt.size()-1],pt[0]));
}
void make_polygon(line poly[],int n)//Generate the points through the lines,use after half-plane intersection
{	line lt[605];
	int i;
	memcpy(lt,poly,sizeof(lt));
	for (i=1;i<n;++i)
		poly[i].p2=poly[i+1].p1=intersect_point(lt[i],lt[i+1]);
	poly[n].p2=poly[1].p1=intersect_point(lt[n],lt[1]);
}
point unit_vec(point a,point b)
{	point p=b-a;
	return p/p.length();
}
/* Relations */
double get_parameter(point a,point b,point p)//parameter of P on vector AB
{	if (a==p)
		return 0;
	if (b==p)
		return 1;
	if (fcmp(a.x-b.x)==0)
		return (p.y-a.y)/(b.y-a.y);
	else return (p.x-a.x)/(b.x-a.x);
}
point intersect_point(point p,point v,point q,point w)//of lines. Ensure the point exist.
{	point u=p-q;
	double t=cp(w-q,u)/cp(v-p,w-q);
	return p+(v-p)*t;
}
point intersect_point(half_plane a,half_plane b)
{	vector u=a.p1-b.p1;
	double t=cp(b.dir(),u)/cp(a.dir(),b.dir());
	return a.p1+a.dir()*t;
}
line midnormal(point a,point b)
{	point mid=(a+b)/2;
	return line(mid,mid+rotate(mid-a,pi/2));
}
double directed_dis(line li,point p)
{	return cp(p-li.p1,li.p2-li.p1)/li.length();
}
bool in_ang(point pl,point p0,point pr,point x)
{	return point_on_ray(x,p0,pl)||point_on_ray(x,p0,pr)||(point_onleft(p0,pr,x)&&!point_onleft(p0,pl,x));
}
bool point_on_left(point a,point b,point p)
{	return fcmp(cp(b-a,p-a))>0;
}
bool point_on_right(point a,point b,point p)
{	return fcmp(cp(b-a,p-a))<0;
}
bool point_on_seg(point p,point a,point b)
{	if (fcmp(cp(p-a,p-b))==0)
	{	if (fcmp(p.x-min(a.x,b.x))>=0)
			if (fcmp(p.x-max(a.x,b.x))<=0)
				if (fcmp(p.y-min(a.y,b.y))>=0)
					if (fcmp(p.y-max(a.y,b.y))<=0)
						return 1;
		return 0;
	}
	return 0;
}
bool point_on_ray(point p,point a,point b)
{   if (p==a)
        return 1;
    if (p==b)
        return 1;
    if (cp(p-a,p-b)==0)
    {   if (b.x>a.x&&p.x>a.x)
            return 1;
        if (b.x<a.x&&p.x<a.x)
        	return 1;
        return 0;
    }
    return 0;
}
point sym_point(point p,line l)
{	point p2;
	double d;
	d=l.a*l.a+l.b*l.b;
	p2.x=(l.b*l.b*p.x-l.a*l.a*p.x-2*l.a*l.b*p.y-2*l.a*l.c)/d;
	p2.y=(l.a*l.a*p.y-l.b*l.b*p.y-2*l.a*l.b*p.x-2*l.b*l.c)/d;
	return p2;
}
int seg_colinear(point a1,point a2,point b1,point b2)
{	if (fcmp(cp(a1-b1,a1-b2))==0&&fcmp(cp(a2-b1,a2-b2))==0)
		return 1;
	else return 0;
}
int seg_inprop_intersect(point a1,point a2,point b1,point b2)
{	double c1,c2,c3,c4;
	if (seg_colinear(a1,a2,b1,b2))
	{	if (fcmp(max(a1.x,a2.x)-min(b1.x,b2.x))<0)
			return 0;
		if (fcmp(max(b1.x,b2.x)-min(a1.x,a2.x))<0)
			return 0;
		return 1;
	}
    c1=cp(a2-a1,b1-a1);
    c2=cp(a2-a1,b2-a1);
    c3=cp(b2-b1,a1-b1);
    c4=cp(b2-b1,a2-b1);
    return fcmp(c1)*fcmp(c2)<=0&&fcmp(c3)*fcmp(c4)<=0;
}
bool seg_prop_intersect(point& a1,point& a2,point& b1,point& b2)
{	double c1,c2,c3,c4;
  	c1=cp(a2-a1,b1-a1);
	c2=cp(a2-a1,b2-a1);
 	c3=cp(b2-b1,a1-b1);
	c4=cp(b2-b1,a2-b1);
 	return fcmp(c1)*fcmp(c2)<0&&fcmp(c3)*fcmp(c4)<0;
}
int seg_intersect_term(point a1,point a2,point b1,point b2)
{	if (seg_colinear(a1,a2,b1,b2))
	{	if (a1==b1&&!point_on_seg(a1,b1,b2))
			return 1;
		if (a2==b1&&!point_on_seg(a2,b1,b2))
			return 1;
		if (a1==b2&&!point_on_seg(a1,b1,b2))
			return 1;
		if (a2==b2&&!point_on_seg(a2,b1,b2))
			return 1;
		return 0;
	}
	if (seg_inprop_intersect(a1,a2,b1,b2))
		return 1;
	return 0;
}
bool point_in_polygon(point &p,polygon &g)
{	int i,wn=0,k,d1,d2;
	int n=g.pt.size();
 	for (i=0;i<n;++i)
	{	point &p1=g.pt[i];
   		point &p2=g.pt[(i+1)%n];
   		if (p1==p||p2==p||point_on_seg(p,p1,p2))
			return true;
   		k=cp(p2-p1,p-p1);
   		d1=p1.y-p.y;
   		d2=p2.y-p.y;
   		if (k>0&&d1<=0&&d2>0)
			++wn;
   		if (k<0&&d2<=0&&d1>0)
			--wn;
 	}
 	if (wn!=0)
	  	return true;
 	return false;
}
bool point_in_polygon(point &p,line g[],int n)
{	int i,wn=0;
	double k,d1,d2;
 	for (i=1;i<=n;++i)
	{	point &p1=g[i].p1;
   		point &p2=g[i].p2;
   		if (p1==p||p2==p||point_on_seg(p,p1,p2))
			return true;
   		k=cp(p2-p1,p-p1);
   		d1=p1.y-p.y;
   		d2=p2.y-p.y;
   		if (fcmp(k)>0&&fcmp(d1)<=0&&fcmp(d2)>0)
			++wn;
   		if (fcmp(k)<0&&fcmp(d2)<=0&&fcmp(d1)>0)
			--wn;
 	}
 	if (wn!=0)
	  	return true;
 	return false;
}
bool point_in_circle(point p,double r,point center=point())//center located at (0,0) as default
{	return fcmp(dist2(p,center)-r*r)<=0;
}
bool point_on_circle(point p,double r,point center=point())//center located at (0,0) as default
{	return fcmp(dist2(p,center)-r*r)==0;
}
bool line_circle_inter(point p1,point p2,double r,point ct=point())//both p1 and p2 are not inside the circle(other situation untested)
{	point p=point_project_on_line(p1,p2,ct);
	if (point_in_circle(p,r,ct))
		return true ;
	return false ;
}
bool seg_circle_inter(point p1,point p2,double r)//center located at (0,0)
{	if (point_in_circle(p1,r)!=point_in_circle(p2,r))
		return true  ;
	point p=point_project_on_line(p1,p2,point());
	if (!point_in_circle(p,r))
		return false ;
	if (fcmp(cp(p1,p)*cp(p2,p))<=0)
		return true ;
	return false ;
}
bool seg_circle_prop_inter(point p1,point p2,point pt,double r)
{	if (point_prop_in_circle(p1,r,pt)!=point_prop_in_circle(p2,r,pt))
		return true;
	point p=point_project_on_line(p1,p2,pt);
	if (!point_in_circle(p,r,pt))
		return false;
	if (fcmp(cp(p1,p)*cp(p2,p))<=0)
		return true;
	return false;
}
pair<point,point> line_circle_inter_point(point p1,point p2,double r,point ct=point())//intersect guaranteed,ordered as p1,ret.first,ret.second,p2 by polar angle
{	point p=point_project_on_line(p1,p2,ct);
	point v=unit_vec(p1,p2);
	double l=sqrt(sqr(r)-sqr(dist(ct,p)));
	return make_pair(p-l*v,p+l*v);
}
pair<point,point> seg_circle_inter_point(point p1,point p2,double r,point ct=point())//intersect guaranteed,ordered as p1,ret.first,ret.second,p2 by polar angle
{	point p=point_project_on_line(p1,p2,ct);
	point v=unit_vec(p1,p2);
	double l=sqrt(sqr(r)-sqr(dist(ct,p)));
	point pa=p-l*v,pb=p+l*v;
	if (point_in_circle(p1,r,ct)!=point_in_circle(p2,r,ct))
		if (point_on_seg(pa,p1,p2))
			if ((pa==p1||pa==p2)&&point_in_circle(pb,r,ct)&&point_on_seg(pb,p1,p2))
				return make_pair(pb,pb);
			else return make_pair(pa,pa);
		else return make_pair(pb,pb);
	if (fcmp(cp(pa,p)*cp(pb,p))<=0)
		return make_pair(pa,pb);
	else throw(make_pair(pa,pb));
}
void circle_inter_point(point p1,double r1,point p2,double r2,vector<point>& v)
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
double sector_area(point p1,point p2,double r)//undirected area, center located at (0,0)
{	p1=p1*r/dist(p1,point());
	p2=p2*r/dist(p2,point());
	double ang=abs(atan2(p1)-atan2(p2));
	if (fcmp(ang-pi)>0)
		ang=2*pi-ang;
	if (fcmp(ang+pi)<0)
		ang=-2*pi-ang;
	return abs(r*r*ang/2);
}
double triangle_circle_inter(point p1,point p2,double r)//triangle formed by (0,0),p1,p2
{	pair<point,point> inter_pair;
	point p3,p4;
	if (point_in_circle(p1,r)&&point_in_circle(p2,r))
		return cp(p1,p2)/2;
	if (!point_in_circle(p1,r)&&!point_in_circle(p2,r))
		if (!line_circle_inter(p1,p2,r))
			return sector_area(p1,p2,r)*fcmp(cp(p1,p2));
		else 
		{	if (!seg_circle_inter(p1,p2,r))
				return sector_area(p1,p2,r)*fcmp(cp(p1,p2));
			inter_pair=line_circle_inter_point(p1,p2,r);
			p3=inter_pair.first,p4=inter_pair.second;
			return cp(p3,p4)/2+(sector_area(p1,p3,r)+sector_area(p4,p2,r))*fcmp(cp(p1,p2));
		}
	p3=seg_circle_inter_point(p1,p2,r).first;
	if (point_in_circle(p1,r))
		return cp(p1,p3)/2+sector_area(p3,p2,r)*fcmp(cp(p1,p2));
	else return sector_area(p1,p3,r)*fcmp(cp(p1,p2))+cp(p3,p2)/2;
}
double polygon_circle_inter(polygon poly,double r)//center located at (0,0)
{	double ans=0;
	int i;
	for (i=0;i<poly.li.size();++i)
		ans+=triangle_circle_inter(poly.li[i].p1,poly.li[i].p2,r);
	return abs(ans);
}
int convex_hull(point p[],int n,point ch[])
{	int i,k,m=0;
	sort(p+1,p+n+1);
	for (i=1;i<=n;++i)
	{	while (m>=2&&cp(ch[m]-ch[m-1],p[i]-ch[m-1])<=0)
			--m;
		ch[++m]=p[i];
	}
	k=m;
	for (i=n-1;i>0;--i)
	{	while (m>k&&cp(ch[m]-ch[m-1],p[i]-ch[m-1])<=0)
			--m;
		ch[++m]=p[i];
	}
	if (n>1)
		--m;
	return m;
}
int half_plane_intersect(line l[],int n,line poly[])
{	point p[605];
	line q[605];
	int i,h,t;
	sort(l+1,l+n+1);
	h=t=1;
	q[1]=l[1];
	for (i=2;i<=n;++i)
	{	while (h<t&&!point_on_left(l[i],p[t-1]))
			--t;
		while (h<t&&!point_on_left(l[i],p[h]))
			++h;
		q[++t]=l[i];
		if (fcmp(cp(q[t].p2-q[t].p1,q[t-1].p2-q[t-1].p1))==0)
		{	--t;
			if (point_on_left(q[t],l[i].p1))
				q[t]=l[i];
		}
		if (h<t)
			p[t-1]=intersect_point(q[t-1],q[t]);
	}
	while (h<t&&!point_on_left(q[h],p[t-1]))
		--t;
	for (i=h;i<=t;++i)
		poly[i-h+1]=q[i];
	return t-h+1;
}//better use make_polygon() to get the points
map<point,map<int,int> > pos;
map<point,vector<int> > h;
void prep_edge()
{	int i;
	map<point,vector<int> >::iterator it;
	for (i=1;i<=m*2;++i)
		h[li[i].p1].push_back(i);
	for (it=h.begin();it!=h.end();++it)
	{	sort(it->second.begin(),it->second.end(),cmp_li);
		for (i=0;i<it->second.size();++i)
			pos[it->first][li[(it->second)[i]].pos]=i;
	}
}
void dfs_subdiv(int x)
{	int next;
	vis[x]=cur;
	poly[cur].pt.push_back(li[x].p1);
	poly[cur].li.push_back(li[x]);
	if (pos[li[x].p2][li[x].pos]==0)
		next=h[li[x].p2][h[li[x].p2].size()-1];
	else next=h[li[x].p2][pos[li[x].p2][li[x].pos]-1];
	if (vis[next]==cur)
		return ;
	else dfs_subdiv(next);
}
void planar_subdiv()
{	int i;
	prep_edge();
	for (i=1;i<=m*2;++i)
		if (vis[i]==0)
		{	++cur;
			dfs_subdiv(i);
		}
	n=0;
	for (i=1;i<=cur;++i)
		if (poly[i].area()>0)
			subdiv[++n]=poly[i];
}
//PSLG
