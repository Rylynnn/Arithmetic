#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 2;
long long mod;
typedef  struct {
    long long  m[MAX][MAX];
} mat;
mat bas,B;
mat mul(mat m1,mat m2){
    int i,j,k;
    mat c;
    for(i = 0; i <MAX; i++)
        for(j = 0; j < MAX; j++){
            c.m[i][j] = 0;
            for(k = 0; k < MAX; k++){
                c.m[i][j] += (m1.m[i][k]*m2.m[k][j])%mod;
                c.m[i][j] %= mod;
            }
            c.m[i][j] %= mod;
    }
    return c;
}
mat pow(long long n){
    mat x = bas,c = B;
    while(n >= 1){
        if(n&1L)c = mul(c,x);
        n >>= 1;
        x = mul(x,x);
    }
    return c;
}
void clearmat(mat a){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            a.m[i][j]=0L;
        }
    }
}
int main()
{
    long long a,b,n,s1,s2,c;
    mat fir,ans,now;
    B.m[0][0]=1;
    B.m[0][1]=0;
    B.m[1][0]=0;
    B.m[1][1]=1;
    while(scanf("%lld%lld%lld%lld",&a,&b,&n,&mod)!=EOF){
        clearmat(bas);
        clearmat(fir);
        clearmat(ans);
        clearmat(now);
        s1=2*(a%mod)%mod;
        s2=((2*((a%mod)*(a%mod))%mod)%mod + (2*b)%mod) % mod;
        //cout<<a<<' '<<b;
        if(n==1){
            printf("%lld\n",s1);
        }
        else if(n==2){
            printf("%lld\n",s2);
        }
        else{
            c=a;
            c*=a;
            c=b-c;
            while(c<0){
                c+=mod;
            }
            //cout<<c;
            bas.m[0][0]=s1;
            bas.m[1][0]=c;
            bas.m[0][1]=1L;
            bas.m[1][1]=0L;
            fir.m[0][0]=s2;
            fir.m[0][1]=s1;
            fir.m[1][0]=0L;
            fir.m[1][1]=0L;
            now=pow(n-2);
            ans=mul(fir,now);
            printf("%lld\n",ans.m[0][0]);
        }
    }
    return 0;
}
