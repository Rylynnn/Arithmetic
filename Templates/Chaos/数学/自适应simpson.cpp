template<class T>
double simpson(const T &f,double a,double b,int n)
{
	const double h=(b-a)/n;
	double ans=f(a)+f(b);
	for (int i=1;i<n;i+=2) ans+=4*f(a+i*h);
	for (int i=2;i<n;i+=2) ans+=2*f(a+i*h);
	return ans*h/3;
}
