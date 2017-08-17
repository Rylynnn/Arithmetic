const double PI = acos(-1.0);
struct complex
{
    double r,i;
    complex(double _r = 0.0,double _i = 0.0){r = _r; i = _i;}
    complex operator +(const complex &b){return complex(r+b.r,i+b.i);}
    complex operator -(const complex &b){return complex(r-b.r,i-b.i);}
    complex operator *(const complex &b){return complex(r*b.r-i*b.i,r*b.i+i*b.r);}
};
void change(complex y[],int len)
{
    int i,j,k;
    for(i=1,j=len/2;i<len-1;i++)
    {
        if(i<j)swap(y[i],y[j]);
        k=len/2;
        while(j>=k)
        {
            j-=k;
            k/=2;
        }
        if(j<k) j+=k;
    }
}
void fft(complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        complex wn(cos(on*2*PI/h),sin(on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                complex u = y[k], t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}
int main()
{
    for(int i=0;i<na;i++)
        x1[i]=complex(s1[na-1-i]-'0',0);
    for(int i=na;i<N;i++)
        x1[i]=complex(0,0);
    for(int i=0;i<nb;i++)
        x2[i]=complex(s2[nb-1-i]-'0',0);
    for(int i=nb;i<N;i++)
        x2[i]=complex(0,0);
    fft(x1,N,1);
    fft(x2,N,1);
    for(int i=0;i<N;i++)
        x1[i]=x1[i]*x2[i];
    fft(x1,N,-1);
}
