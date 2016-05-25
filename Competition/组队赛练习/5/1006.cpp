#include <cstdio>
int p[5009],pp[5009],k[N],a[N],b[N];
int num;
double y(double x,int i){
    return k*(x-a)*(x-a)+b;
}
double func(double a,double b,double c){
    int m,n,delta=b*b-4*a*c;
    if(delta==0){
        m=(-b+sqrt(delta))/(2*a);
        if(m>=0&&m<=100)
            p[num++]=m;
    }
    else if(delta>0){
        m=(-b+sqrt(delta))/(2*a);
        n=(-b-sqrt(delta))/(2*a);
        if(m>=0&&m<=100){
            p1[num++]=m;
            p2[num++]=n;
        }
    }
    else{
        return -1;
    }
}
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            num=0;
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                scanf("%d%d%d",,&k[i],&a[i],&b[i]);
            }
            for(int i=1;i<n;i++){
                for(int j=0;j<i;j++){
                    func(k[i]-k[j],-(2*a[i]k[i]-2*a[j]-k[j]),a[i]*a[i]*k[i]-a[j]*a[j]*k[j]+b[i]-b[j]);
                }
            }
            sort(p,p+num);
            for(int i=1;i<num;i++){
                mid=(p[i]+p[i-1])/2;
                minm=100;
                pp[i]=-1;
                for(int j=0;j<n;j++){
                    if(minm>y(mid,j)){
                        pp[i]=j;
                        minm=min(minm,y(mid,j));
                    }

                }
            }
        }
    }
    return 0;
}
