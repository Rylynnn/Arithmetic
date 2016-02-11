#include <cstdio>
#include <cstring>

using namespace std;

const long long MOD=1000000007;

long long f[101];
int a[101][101];
bool b[101];

void Init() {
    f[0]=f[1]=1;
    for(long long i=2;i<=100;++i)
        f[i]=(f[i-1]*i)%MOD;
}

long long quickpow(long long m,long long n) {
    long long b=1;
    while(n>0){
        if (n&1)
            b=(b*m)%MOD;
        n=n>>1;
        m=(m*m)%MOD;
    }
    return b;
}

int n,m;

bool judge() {
    int i,j,x;
    for(i=1;i<=n;++i) {
        x=i;
        for(j=m;j>=1;--j)
            x=a[j][x];
        if(x!=i)
            return false;
    }
    return true;
}

int main() {
    int i,j,k;
    //bool ok;
    Init();
    while(2==scanf("%d%d",&n,&m)) {
        bool fi=false;
        int num=0;
        for(k=1;k<=m;k++){
            for(i=1;i<=n;i++){
                scanf("%d",&a[k][i]);
                if(a[k][i]==-1){
                    num++;
                    //p=1;
                    //printf("%I64d ",num);
                    break;
                }
                memset(b,0,sizeof(b));
                if(b[a[k][i]]){
                    fi=true;
                    //break;
                }
                else{
                    b[a[k][i]]=1;//判函数可用性
                }
                //printf("%I64d ",a);
            }
            /*if(fi){
                break;
            }*/
        }
        if(num==0)
            printf("%d\n",judge()?1:0);
        else
            printf("%I64d\n",!fi?quickpow(f[n],num-1):0);
    }
    return 0;
}
