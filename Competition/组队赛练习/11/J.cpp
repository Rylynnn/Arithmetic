#include <cstdio>
#include <cstring>
#define MAXN 10000007
#define MOD 1000000007
#define ll long long
using namespace std;
char p[2007][2007],m[2007][2007];
int b[2007],a[2007][2007];
const int mod1=233,mod2=17;
int hp,wp,hm,wm;
int main()
{
    freopen("a12.txt","r",stdin);
    int p1[2007],p2[2007];
    p1[0]=1,p2[0]=1;
    for(int i=1;i<2007;i++){
        p1[i]=p1[i-1]*mod1;
        p2[i]=p2[i-1]*mod2;
    }
    while(scanf("%d%d%d%d",&hp,&wp,&hm,&wm)!=EOF){
        for(int i=1;i<=hp;i++){
            scanf("%s",p[i]+1);
        }
        int res=0;
        for(int i=1;i<=hm;i++){
            scanf("%s",m[i]+1);
        }
        for(int i=1;i<=hp;i++){
            int temp=0;
            for(int j=1;j<=wp;j++){
                temp=temp*mod1+p[i][j];
            }
            res=res*mod2+temp;
        }
        memset(a,0,sizeof(a));
        for(int i=1;i<=hm;i++){
            memset(b,0,sizeof(b));
            for(int j=1;j<=wm;j++){
                b[j]=b[j-1]*mod1+m[i][j];
            }
            for(int j=wp;j<=wm;j++){
                a[i][j]=a[i-1][j]*mod2+b[j]-b[j-wp]*p1[wp];
            }
        }
        int ans=0;
        for(int i=hp;i<=hm;i++){
            for(int j=wp;j<=wm;j++){
                if(a[i][j]-a[i-hp][j]*p2[hp]==res){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
