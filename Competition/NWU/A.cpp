#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
void ip();
bool prime[20010];
int main()
{
    int n,i,j;
    int p[20010];
    int a[20010];
    while(scanf("%d",&n)){
        memset(prime,0,sizeof(prime));
        ip();
        memset(p,0,sizeof(p));
        int maxnum=-100;
        int num=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            for(j=1;j<=sqrt(a[i]);j++){
                if(a[i]%j==0){
                    if(prime[a[i]/j]==1){
                        p[a[i]]=a[i]/j;
                        //printf("%d\n",p[a[i]]);
                        break;
                    }
                }
            }
        }
        for(i=1;i<=n;i++){
                //printf("%d",p[a[i]]);
            if(p[a[i]]>maxnum){
                maxnum=p[a[i]];
                num=i;
            }
        }
        printf("%d\n",a[num]);
    }
}
void ip(){
    prime[0]=prime[1]=0;prime[2]=1;
    int i,j;
    for(i=3;i<20010;i++){
        prime[i]=i%2==0?0:1;
    }
    int t=(int)sqrt(20010*1.0);
    for(i=3;i<=t;i++){
        if(prime[i]){
            for(j=i*i;j<20010;j+=2*i){
            prime[j]=0;
            }
        }
    }
}
