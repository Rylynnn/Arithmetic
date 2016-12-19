#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node{
    int num;int mon;int nn;
}p[10007];
int pp[10007];
bool cmp(node a,node b){
    if(a.mon!=b.mon){
        return a.mon>b.mon;
    }
    else{
        if(a.nn!=b.nn){
            return a.nn>b.nn;
        }
        else{
            if(a.num!=b.num){
                return a.num<b.num;
            }
        }
    }
}
int main()
{
    int n,k,a,b,sum;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            p[i].num=i;
            p[i].mon=0;
            p[i].nn=0;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            sum=0;
            memset(pp,0,sizeof(pp));
            for(int j=1;j<=k;j++){
                scanf("%d%d",&a,&b);
                if(pp[a]==0){
                    pp[a]=1;
                    p[a].nn++;
                    p[a].mon+=b;
                    sum+=b;
                }
            }
            p[i].mon-=sum;
        }
        sort(p+1,p+n+1,cmp);
        for(int i=1;i<=n;i++){
            printf("%d ",p[i].num);
            /*
            这一段出了问题？？？？
            if(p[i].mon<0){
                printf("%d.%d",p[i].mon/100,(-p[i].mon%100));
            }
            else{
                printf("%d.%d",p[i].mon/100,p[i].mon%100);
            }
            printf("\n");*/
            printf("%.2f\n",0.01*p[i].mon);
        }
    }
    return 0;
}
