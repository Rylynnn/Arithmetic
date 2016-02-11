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
int p[100005],c[100005];
int Prime(){
    memset(c,0,sizeof(c));
    memset(p,0,sizeof(p));
    c[0]=c[1]=0;c[2]=1;
    for(int i=3;i<100005;i++)
        c[i]=i%2==0?0:1;
    int t=(int)sqrt(100005*1.0);
    for(int i=3;i<=t;i++)
        if(c[i])
        for(int j=i*i;j<100005;j+=2*i)
            c[j]=0;
    int num=0;
    for(int i=1;i<100005;i++){
        if(c[i]){
            p[++num]=i;
            //printf("%d ",num);
        }
    }
    return num;
}
bool cmp(LL a,LL b){
    return a<b;
}
int main()
{
    int T,n,point,k;
    LL num,a,i,j,b[110],min1,min2;
    scanf("%d",&T);
    k=Prime();
    while(T--){
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        min1=min2=MAX;
        point=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&b[i]);
        }
        //printf("%d",point);
        sort(b+1,b+n+1,cmp);
        for(i=1;i<=k;i++){
            for(j=1;j<=n;j++){
                    //printf("%d %d",b[j],p[i]);
                if(min1!=MAX&&min2!=MAX){
                    break;
                }
                if(b[j]%p[i]==0&&p[i]<min1){
                    min1=p[i];
                    //printf("%I64d ",min1);
                }
                else if(b[j]%p[i]==0&&p[i]<min2){
                    min2=p[i];
                //printf("%I64d ",min2);
                }
            }
        }
        if(min1!=MAX&&min2!=MAX){
            printf("%I64d\n",min1*min2);
        }
        else{
            printf("-1\n");
        }
    }
    //printf("%I64d",num);
    return 0;
}
