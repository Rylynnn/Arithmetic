#include <cstdio>
#include <cstring>

using namespace std;

const long long MOD=1000000007;

long long f[101];
int a[101][101];
bool vis[101];

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

bool Judge() {
    int i,j,x;
    for(i=1;i<=n;++i) {
        x=i;
        for(j=m-1;j>=0;--j){
            x=a[j][x];
            printf("%d ",x);
        }
        if(x!=i)
            return false;
    }
    return true;
}

int main() {
    int i,j,cnt;
    bool ok;
    Init();
    while(2==scanf("%d%d",&n,&m)) {
        cnt=0,ok=true;
        for(i=0;i<m;++i) {
            scanf("%d",&a[i][1]);
            if(a[i][1]==-1)
                ++cnt;
            else {
                memset(vis,false,sizeof(vis));
                vis[a[i][1]]=true;
                for(j=2;j<=n;++j) {
                    scanf("%d",&a[i][j]);
                    if(vis[a[i][j]])
                        ok=false;
                    else
                       vis[a[i][j]]=true;
                }
            }
        }
        if(cnt==0)
            printf("%d\n",Judge()?1:0);
        else
            printf("%I64d\n",ok?quickpow(f[n],cnt-1):0);
    }
    return 0;
}
