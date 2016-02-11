#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <string>
#include <set>
#define MAX 0x7fffffff
#define eps 1e-8
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
int p[100010];
LL pow_mod(LL aa,LL ii,LL nn)
{
    if(ii==0)
        return 1%nn;
    LL temp=pow_mod(aa,ii>>1,nn);
    temp=temp*temp%nn;
    if(ii&1)
        temp=temp*aa%nn;
    return temp;
}
bool test (LL n,LL a,LL d)
{
    if(n==2)
        return true;
    if(n==a)
        return true;
    if((n&1)==0)
        return false;
    while(!(d&1))
        d=d>>1;
    LL t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=(LL)t*t%n;
        d=d<<1;
    }
    return (t==n-1||(d&1)==1);
}
bool isPrime(LL n)
{
    if(n<2)
        return false;
    LL a[]= {2,3,5,7,61};
    for(int i=0; i<=4; i++)
        if(!test(n,a[i],n-1))
            return false;
    return true;
}
int prime(){
    int num=0,i;
    memset(p,0,sizeof(p));
    for(i=2;i<=100005;i++){
        if(isPrime(i)){
            p[++num]=i;
            //printf("%d ",i);
        }
    }
    return num;
}
int main()
{
    int T,n,k;
    LL num,a,i,j,b[110],min1,min2;
    scanf("%d",&T);
    k=prime();
    while(T--){
        scanf("%d",&n);
        num=0;
        memset(b,0,sizeof(b));
        min1=min2=MAX;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a);
            if(!isPrime(a)){
                b[++num]=a;
            }
            else{
                if(a<min1){
                    min1=a;
                }
                else if(a<min2){
                    min2=a;
                }
            }
        }
        for(i=1;i<=k;i++){
            for(j=1;j<=num;j++){
                if(b[j]%p[i]==0&&p[i]<min1){
                    min1=p[i];
                }
                else if(b[j]%p[i]==0&&p[i]<min2){
                    min2=p[i];
                }
            }
        }
        if(min1!=MAX&&min2!=MAX){
            printf("%I64d",min1*min2);
        }
        else{
            printf("-1");
        }
    }
    //printf("%I64d",num);
    return 0;
}
