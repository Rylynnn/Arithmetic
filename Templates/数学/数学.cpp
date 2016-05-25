//矩阵 

//矩阵类
const int MAXN=1010;
const int MAXM=1010;
struct Matrix
{
	int n,m;
	int a[MAXN][MAXM];
	void clear()
	{
		n=m=0;
		memset(a,0,sizeof(a));
	}
	Matrix operator +(const Matrix &b) const
	{
		Matrix tmp;
		tmp.n=n; tmp.m=m;
		for (int i=0;i<n;i++)
		  for (int j=0;j<m;j++)
		    tmp.a[i][j]=a[i][j]+b.a[i][j];
	    return tmp;
	}
	Matrix operator -(const Matrix &b) const
	{
		Matrix tmp;
		tmp.n=n; tmp.m=m;
		for (int i=0;i<n;i++)
		  for (int j=0;j<m;j++)
		    tmp.a[i][j]=a[i][j]-b.a[i][j];
		return tmp;
    }
    Matrix operator *(const Matrix &b) const
    {
		Matrix tmp;
		tmp.clear();
		tmp.n=n;
		tmp.m=b.m;
		for (int i=0;i<n;i++)
		  for (int j=0;j<b.m;j++)
		    for (int k=0;k<m;k++)
		      tmp.a[i][j]+=a[i][k]*b.a[k][j];
		return tmp;
    }
};
//Gauss消元 
const double EPS=1e-12;
inline int solve(double a[][MAXN],bool l[],double ans[],const int &n)
{
	int res=0,r=0;
	for (int i=0;i<n;i++)
	  l[i]=false;
	for (int i=0;i<n;i++)
	{
		for (int j=r;j<n;j++)
		  if (fabs(a[i][j])>EPS)
		  {
				for (int k=i;i<=n;k++)
				   swap(a[j][k],a[r][k]);
				break;
		  }
		if (fabs(a[r][i])<EPS)
		{
			res++;
			continue;
		}
		for (int j=0;j<n;j++)
		  if (j!=r&&fabs(a[i][j])>EPS)
		  {
			     double tmp=a[j][i]/a[r][i];
				for (int k=i;k<=n;k++)
				  a[j][k]-=tmp*a[r][k];
		  }
		l[i]=true;
		r++;
	}
	for (int i=0;i<n;i++)
	  if (l[i])
	    for (int j=0;j<n;j++)
	      if (fabs(a[j][i])>0)  
	        ans[i]=a[j][n]/a[j][i];
	return res;
}
//矩阵的逆 
inline vector<double> operator * (vector<double> a, double b)
{
	int N=a.size();
	vector<double>  res(N,0);
	for (int i=0;i<N;i++)
	  res[i]=a[i]*b[i];
	return res;
}
inline vector<double> operator - (vector<double> a,vector<double> b)
{
	int N=a.size();
	vector<double> res(N,0);
	for (int i=0;i<N;i++)
	  res[i]=a[i]-b[i];
	return res;
}
inline void inverse(vector<double> A[], vector<double> C[],int N)
{
	for (int i=0;i<N;i++)
	  C[i]=vector<double>(N,0);
	for (int i=0;i<N;i++)
	  C[i][i]=1;
	for (int i=0;i<N;i++)
	{
		for (int j=i;j<N;j++)
		  if (fabs(A[j][i]>0)
		  {
				swap(A[i],A[j]);
				swap(C[i],C[j]);
				break;
		  }
		C[i]=C[i]*(1/A[i][i]);
		A[i]=A[i]*(1/A[i][i]);
		for (int j=0;j<N;j++)
		  if (j!=i&&fabs(A[j][i]>0))
		  {
				C[j]=C[j]-C[i]*A[j][i];
				A[j]=A[j]-A[i]*A[j][i];
		  }
    }
} 
//常系数线性齐次递推 
int solve(int a[],int b[],int n,int t)
{
	Matrix M,F,E;
	M.clear(),F.clear(),E.clear();
	M.n=M.m=n;
	E.n=E.m=n;
	F.n=n,F.m=1;
	for (int i=0;i<n-1;i++)
	  M.a[i][i+1]=1;
	for (int i=0;i<n;i++)
	{
		M.a[n-1][i]=a[i];
        F.a[i][0]=b[i];
        E.a[i][i]=1;
	}
	if (t<n) return F.a[t][0];
    for (t-=n;t;t/=2)
    {
		if (t&1) M*E;
		M=M*M;
	}
	F=E*F;
	return F.a[n-1][0];
}
 
 
//整除与剩余 

//欧几里得定理
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
//扩展欧几里得定理
int extended_gcd(int a,int b,int &x,int &y)
{
    if (b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        int r=extended_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}
//单变元线性模方程

vector <long long> line_mod_equation(long long a,long long b,long long n)
{
    long long x,y;
    long long d=gcd(a,n,x,y);
    ans.clear();
    if (b%d==0)
    {
        a%=n;
        x+=n;
        x%=n;
        ans.push_back(x*(b/d)%(n/d));
        for (long long i=1;i<d;i++)
            ans.push_back((ans[0]+i*n/d)%n);
    }
    return ans;
}

//中国剩余定理
int CRT(int a[],int m[],int n)
{
    int M=1;
    for (int i=0;i<n;i++)
        M*=m[i];
    int ret=0;
    for (int i=0;i<n;i++)
    {
        int x,y;
        int tm=M/m[i];
        extend_gcd(tm,m[i],x,y);
        ret=(ret+tm*x*a[i])%M;
    }
    return (ret+M)%M;
}
//求原根
vector <long long>a;
bool g_test(long long g,long long p)
{
    for (long long i=0;i<a.size();i++)
        if (pow_mod(g,(p-1)/a[i],p)==1) return 0;
    return 1;
}
long long primitive_root(long long p)
{
    long long tmp=p-1;
    for (long long i=2;i<=tmp/i;i++)
        if (tmp%i==0)
        {
            a.push_back(i);
            while (tmp%i==0)
                tmp/=i;
        }
    if (tmp!=1)
    {
        a.push_back(tmp);
    }
    long long g=1;
    while (true)
    {
        if(g_test(g,p)) return g;
        g++;
    }
}
//平方剩余
int modsqr(int a,int n)
{
    int b,k,i,x;
    if (n==2) return a%n;
    if (pow_mod(a,(n-1)/2,n)==1)
    {
        if (n%4==3)  x=pow_mod(a,(n+1)/4,n);
              else   
              {
                  for (b=1;pow_mod(b,(n-1)/2,n)==1;b++);
                  i=(n-1)/2;
                  k=0;
                  do
                  {
                      i/=2;
                      k/=2;
                      if ((pow_mod(a,i,n)*(long long)pow_mod(b,k,n)+1)%n==0)  k+=(n-1)/2;
                  }
                  while (i%2==0)
                  x=(pow_mod(a,(i+1)/2,n)*(long long)pow_mod(b,k/2,n))%n;
              }
             if (x*2>n) x=n-x;
             return x;
    }
    return -1;
}
                  
//离散对数
long long bsgs(int x,int n,int m)
{
    map<long long,int> rec;
    int s=(int)(sqrt((double)m));
    for(;(long long)s*s <= m;)
        s++;
    long long cur=x%m;
    rec[1]=0;
    for (int i=1;i<s;i++)
    {
        if (rec[cur]==0&&cur!=1) rec[cur]=i;
        cur=(cur*x)%m;
    }
    long long mul=cur;
    cur=1;
    for (int i=0;i<s;i++)
    {
        long long more=(long long)n*pow_mod(cur,m-2,m)%m;
        if (rec.count(more)) return i*s+rec[more];
        cur=(cur*mul)%m;
    }
    return -1;
}

//N次剩余
vector <int> residue(int p,int N,int a)
{
    int g=primitive_root(p);
    long long m=discrete_log(g,a,p);
    vector<int> ret;
    if (a==0)
    {
        ret.push_back(0);
        return ret;
    }
    if (m==-1) return ret;
    long long A=N,B=p-1,C=m,x,y;
    long long d=extended_gcd(A,B,x,y);
    if (c%d!=0) return ret;
    x=x*(C/d)%B;
    long long delta=B/d;
    for (int i=0;i<d;i++)
    {
        x=((x+delta)%B+B)%B;
        ret.push_back((int)pow_mod(g,x,p));
    }
    sort(ret.begin(),ret.end());
    ret.erase(unqinue(ret.begin(),ret.end()),ret.end());
    return ret;
}





//素数与函数 

//素数筛法
#define maxn 1000000
bool valid[maxn];
void getPrime(int n,int &tot,int ans[maxn])
{
	memset(valid,true,sizeof(valid));
	for (int i=2;i<=n;i++)
	{
		if (valid[i])
		{
			tot++;
			ans[tot]=i;
			for (int j=2;j<=n/i;j++)
			  valid[i*j]=0;
		}
	}
}
//素数判定 
bool test(int n,int a,int d)
{
	if (n==2) return true;
	if (n==a) return true;
	if ((n&1)==0) return false;
	while (!(d&1)) d=d>>1;
	int t=pow_mod(a,d,n);
	while ((d!=n-1)&&(t!=1)&&(t!=n-1))
	{
		t=(long long) t*t%n;
		d=d<<1;
    }
    return(t==n-1||(d&1)==1);
}

bool isPrime(int n)
{
	if (n<2) return false;
	int a[3]={2,3,61};
	for (int i=0;i<=2;i++)
	  if (!test(n,a[i],n-1)) return false;
	return true;
}
//质因数分解 
void factor(int n,int a[maxn],int b[maxn],int &tot)
{
	int temp,i,now;
	temp=(int)((double)sqrt(n)+1);
	tot=0;
	now=n;
	for (i=2;i<=temp;i++)
	  if (now%i==0)
	  {
			a[tot++]=i;
			b[tot]=0;
			while (now%i==0)
			{
				b[tot]++;
				now/=i;
		    }
	  }
	if (now!=1)
	{
		a[++tot]=now;
		b[tot]=1;
    }
}
//欧拉函数计算 
int minDiv[maxn],phi[maxn],sum[maxn];
void getPhi()
{
	for (int i=1;i<maxn;i++)
	  minDiv[i]=i;
	for (int i=2;i*i<maxn;i++)
	{
		if (minDiv[i]==i)
		{
			for (int j=i*i;j<max;j+=i)
			  minDiv[j]=i;
	    }
    }
    phi[1]=1;
    for (int i=2;i<max;i++)
    {
		phi[i]=phi[i/minDiv[i]];
		if ((i/minDiv[i])%minDiv[i]==0)  phi[i]*=minDiv[i];
	    else phi[i]*=minDiv[i]-1;
    }
}
//Mobius函数计算 
const int n=1<<20;
int mu[n];
int getMu()
{
	for (int i=1;i<=n;i++)
	{
		int target=i==1?1:0;
		int delta=target-mu[i];
		mu[i]=delta;
		for (int j=i+i;j<=n;j+=i)
		  mu[j]+=delta;
    }
}





//数值计算
 
//数值积分
template<class T>
double simpson(const T &f,double a,double b,int n)
{
	const double h=(b-a)/n;
	double ans=f(a)+f(b);
	for (int i=1;i<n;i+=2) ans+=4*f(a+i*h);
	for (int i=2;i<n;i+=2) ans+=2*f(a+i*h);
	return ans*h/3;
}
template<class T>
double romberg(const T &f,double a,double b,double eps=1e-8)
{
	vector<double>t;
	double h=b-a,last,curr;
	int k=1,i=1;
	t.push_back(h*(f(a)+f(b))/2);
	do
	{
		last=t.back();
		curr=0;
		double x=a+h/2;
		for (int j=0;j<k;j++)
		{
			curr+=f(x);
			x+=h;
		}
		curr=(t[0]+h*curr)/2;
		double k1=4.0/3.0,k2=1.0/3.0;
		for (int j=0;j<i;j++)
		{
			double temp=k1*curr-k2*t[j];
			t[j]=curr;
			curr=temp;
			k2/=4*k1-k2;
			k1=k2+1;
		}
		t.push_back(curr);
		k*=2;
		h/=2;
		i++;
	}while (fabs(last-curr)>eps);
	return t.back();
}
//高阶代数方程求根 
const double EPS=1E-12;
const double inf=1E+12;

inline int sign(double x)
{
	return x<-EPS?-1:x>EPS;
}
inline double get(const vector<double>&coef,double x)
{
	double e=1,s=0;
	for (int i=0;i<coef.size();i++)
	  s+=coef[i]*e,e*=x;
	return s;
}
double find(const vector<double>&coef,int n,double lo,double hi)
{
	double sign_lo,sign_hi;
	if ((sign_lo=sign(get(coef,lo)))==0) return lo;
	if ((sign_hi=sign(get(coef,hi)))==0) return hi;
	if (sign_lo*sign_hi>0) return inf;
	for (int step=0;step<100 && hi-lo>EPS;step++)
	{
		double m=(lo+hi)*.5;
		int sign_mid=sign(get(coef,m));
		if (sign_mid==0) return m;
		if (sign_lo*sign_mid<0)  hi=m;
		                    else lo=m;
	}
	return (lo+hi)*.5;
}

vector <double>equation(vector<double> coef,int n)
{
	vector<double> ret;
	if (n==1)
	{
		if (sign(coef[1])) ret.push_back(-coef[0]/coef[1]);
		return ret;
	}
	vector<double> dcoef(n);
	for (int i=0;i<n;i++)
	  dcoef[i]=coef[i+1]*(i+1);
	vector<double> droot=solve(dcoef,n-1);
	droot.insert(droot.begin(),-inf);
	droot.push_back(inf);
	for (int i=0;i+1<droot.size();i++)
	{
		double tmp=find(coef,n,droot[i],droot[i+1]);
		if (tmp<inf) ret.push_back(tmp);
	}
	return ret;
}




//其他

//快速幂 
long long pow_mod(long long a,long long i,long long n)
{
	if (i==0) return 1%n;
	long long temp=pow_mod(a,i>>1,n);
    temp=temp*temp%n;
    if (i&1) temp=(long long) temp*a%n;
    return temp;
}

//进制转换 
string transform(int x,int y,string s)
{
	string res="";
	int sum=0;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]=='-') continue;
		if (s[i]>='0'&&s[i]<='9')
		{
			sum=sum*x+s[i]-'0';
		}
		else  sum=sum*x+s[i]-'A'+10;
	}
	while (sum)
	{
		char tmp=sum%y;
		sum/=y;
		if (tmp<=9)  tmp+='0';
		       else  tmp=tmp-10+'A';
		res=tmp+res;
	}
	if (res.length()==0) res="0";
	if (s[0]=='-') res='-'+res;
	return res;
}
//格雷码 
vector<int> Gray_Create(int n)
{
	vector<int>res;
	res.clear();
	for (int i=0;i<(1<<n);i++)
	   res.push_back(i^(i>>1));
	return res;
}
//高精度整数 
const int ten[4]={1,10,100,1000};
const int maxl=1000;
struct BigNumber
{
	int d[maxl];
	BigNumber (string s)
	{
		int len=s.size();
		d[0]=(len-1)/4+1;
		int i,j,k;
		for (i=1;i<maxl;i++)
		  d[i]=0;
		for (i=len-1;i>=0;i--)
		{
			j=(len-i-1)/4+1;
			k=(len-i-1)%4;
			d[j]+=ten[k]*(s[i]-'0');
		}
		while (d[0]>1&&d[d[0]]==0) 
		  d[0]--; 
	}
	BigNumber()
	{
		*this=BigNumber(string("0"));
	}
	string toString()
	{
		string s("");
		int i,j,temp;
		for (i=3;i>=1;i--)
		  if (d[d[0]]>=ten[i]) break;
		temp=d[d[0]];
		for (j=i;j>=0;j--)
		{
			s=s+(char)(temp/ten[j]+'0');
			temp%=ten[j];
		}
		for (i=d[0]-1;i>0;i--)
		{
			temp=d[i];
			for (j=3;j>=0;j--)
			{
				s=s+(char)(temp/ten[j]+'0');
				temp%=ten[j];
			}
		}
		return s;
	}
}zero("0"),d,temp,mid1[15];

bool operator < (const BigNumber &a, const BigNumber &b)
{
	if (a.d[0]!=b.d[0]) return a.d[0]<b.d[0];
	int i;
	for (i=a.d[0];i>0;i--) 
	  if (a.d[i]!=b.d[i]) return a.d[i]<b.d[i];
	return false;
}

BigNumber operator +(const BigNumber &a,const BigNumber &b)
{
	BigNumber c;
	c.d[0]=max(a.d[0],b.d[0]);
	int i,x=0;
	for (i=1;i<=c.d[0];i++)
	{
		x=a.d[i]+b.d[i]+x;
		c.d[i]=x%10000;
		x/=10000;
	}
	while (x!=0)
	{
		c.d[++c.d[0]]=x%10000;
		x/=10000;
	}
	return c;
}

BigNumber operator -(const BigNumber &a,const BigNumber &b)
{
	BigNumber c;
	c.d[0]=a.d[0];
	int i,x=0;
	for (i=l;i<=c.d[0];i++)
	{
		x=10000+a.d[i]-b.d[i]+x;
		c.d[i]=x%10000;
		x=x/10000-1;
	}
	while ((c.d[0]>1)&&(c.d[c.d[0]]==0)) c.d[0]--;
	return c;
}

BigNumber operator * (const BigNumber &a,const BigNumber &b)
{
	BigNumber c;
	c.d[0]=a.d[0]+b.d[0];
	int i,j,x;
	for (i=1;i<=a.d[0];i++)
	{
		x=0;
		for (j=1;j<=b.d[0];j++)
		{
			x=a.d[i]*b.d[j]+x+c.d[i+j-1];
			c.d[i+j-1]=x%10000;
			x/=10000;
		}
		c.d[i+b.d[0]]=x;
	}
	while ((c.d[0]>1)&&(c.d[c.d[0]]==0)) c.d[0]--;
	return c;
}

bool smaller (const BigNumber &a,const BigNumber &b,int delta)
{
	if (a.d[0]+delta!=b.d[0]) return a.d[0]+delta<b.d[0];
	int i;
	for (i=a.d[0];i>0;i--)
	  if (a.d[i]!=b.d[i+delta])  return a.d[i]<b.d[i+delta];
	return truel
}

void Minus(BigNumber &a, const BigNumber &b,int delta)
{
	int i,x=0;
	for (i=1;i<=a.d[0]-delta;i++)
	{
		x=10000+a.d[i+delta]-b.d[i]+x;
		a.d[i+delta]=x%10000;
		x=x/10000-1;
	}
	while ((a.d[0]>1)&&(a.d[a.d[0]]==0) a.d[0]--;
}

BigNumber operator *(const BigNumber &a,const int &k)
{
	BigNumber c;
	c.d[0]=a.d[0];
	int i,x=0;
	for (i=1;i<=a.d[0];i++)
	{
		x=a.d[i]*k+x;
		c.d[i]=x%10000;
		x/=10000;
	}
	while (x>0)
	{
		c.d[++c.d[0]]=x%10000;
		x/=10000;
	}
	while ((c.d[0]>1)&&(c.d[c.d[0]]==0) c.d[0]--;
	return c;
}

BigNumber operator / (const BigNumber &a,const BigNumber &b)
{
	BigNumber c;
	d=a;
	int i,j,temp;
	mid1[0]=b;
	for (i=1;i<=13;i++)
	  mid1[i]=mid1[i-1]*2;
	for (i=a.d[0]-b.d[0];i>=0;i--)
	{
		temp=8192;
		for (j=13;j>=0;j--)
		{
			if (smaller(mid1[j],d,i))
			{
				Minus(d,mid1[j],i);
				c.d[i+1]+=temp;
			}
			temp/=2;
		}
	}
	c.d[0]=max(1,a.d[0]-b.d[0]+1);
	while ((c.d[0]>1)&&(c.d[c.d[0]]==0)  c.d[0]--;
	return c;
}

bool operator ==(const BigNumber &a,cosnt BigNumber &b)
{
	int i;
	if (a.d[0]!=b.d[0]) return false;
	for (i=1;i<=a.d[0];i++)
	  if (a.d[i]!=b.d[i]) return false;
	return true;
}

//快速傅里叶变换 
typedef long long Int64;
const int maxn=2000000;
const double pi=acos(-1.0);

typedef complex<double> Complex;

void build (Complex_P[],Complex P[],int n,int m,int curr,int &cnt)
{
	if (m==n) _P[cnt++];
	else
	{
		build(_P,P,n,m*2,curr,cnt);
		build(_P,P,n,m*2,curr+m,cnt);
	}
}

void FFT(Complex P[],int n,int oper)
{
	static Complex _P[maxn];
	int cnt=0;
	build(_P,P,n,1,0,cnt);
	copy(_P,_P+n,P);
	for (int d=0;(1<<d)<n;d++)
	{
		int m=1<<d;
		int m2=m*2;
		double p0=pi/m*oper;
		Complex unit_p0=Complex(cos(p0),sin(p0));
		for (int i=0;i<n;i+=m2)
		{
			Complex unit=1;
			for (int j=0;j<m;j++)
			{
				Complex &P1=P[i+j+m],&P2=P[i+j];
				Complex t=unit*P1;
				P1=P2-t;
				P2=P2+t;
				unit=unit*unit_p0;
			}
		}
	}
}

//分数类 
struct Fraction
{
	long long num,den;
	Fraction(long long num=0,long long den=1)
	{
		if (den<0)
		{
			num=-num;
			den=-den;
		}
		assert(den!=0);
		long long g=gcd(abs(num),den);
		this->num=num/g;
		this->den=den/g;
	}
	Fraction operator +(const Fraction &o) const
	{
		return Fraction(num*o.den+den*o.num,den*o.den);
	}
	Fraction operator -(const Fraction &o) const
	{
		return Fraction(num*o.den-den*o.num,den*o.den);
    }
    Fraction operator *(const Fraction &o) const
    {
		return Fraction(num*o.num,den*o.den);
	}
	Fraction operator /(const Fraction &o) const
	{
		return Fraction(num*o.den,den*o.num);
	}
	bool operator <(const Fraction &o) const
	{
		return num*o.den<den*o.num;
	} 
	bool operator >(const Fraction &o) const
	{
		return num*o.den>den*o.num;
	} 
	bool operator ==(const Fraction &o) const
	{
		return num*o.den==den*o.num;
	}
};
//全排列散列 
void intToArray(int x,int a[MAXN])
{
	bool used[MAXN];
	int i,j,temp;
	for (i=1;i<=n;i++)
	  used[i]=false;
	for (i=1;i<=n;i++)
	{
		temp=x/factorial[n-i];
		for (j=1;j<=n;j++)
		  if (!used[j])
		  {
				if (temp==0) break;
				temp--;
		  }
		used[j]=true;
		x%=factorial[n-i];
	}
}

int arrayToInt(int a[MAXN])
{
    int ans,i,j,temp;
    ans=0;
    for (i=1;i<=n;i++)
    {
		temp=a[i]-1;
		for (j=1;j<i;j++)
		  if (a[j]<a[i]) temp--;
		ans+=factorial[n-i]*temp;
	}
	return ans;
}
