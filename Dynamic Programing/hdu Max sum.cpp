#include<cstdio>
#include<algorithm>
using namespace std;
int a[10000000];
struct b{
    int v;
    int h,t;
}dp[1000000];
void dodp(int i);
int main()
{
    int num,n,i,maxm,k;
    while(~scanf("%d",&num)){
        k=0;
        while(++k<=num){
            scanf("%d%d",&n,&a[1]);
            int p=1;
            int point=0;
            dp[1].v=a[1];
            dp[1].h=1;
            dp[1].t=1;
            for(i=2;i<=n;i++){
                point=1;
                scanf("%d",&a[i]);
                if(a[i]<0)p++;
                dodp(i);
            }
            if(k!=1)printf("\n");
            printf("Case %d:\n",k);
            //if(p==n&&point==1)printf("0 %d %d\n",a[1],a[n]);
            maxm=0;
            dp[maxm].v=-100000;
            for(i=1;i<=n;i++){
                if(dp[i].v>dp[maxm].v)maxm=i;
            }
            printf("%d %d %d\n",dp[maxm].v,dp[maxm].h,dp[maxm].t);
        }
    }
    return 0;
}
void dodp(int i){
    if(dp[i-1].v<0){
        dp[i].v=a[i];
        dp[i].h=i;
        dp[i].t=i;
    }
    else if(dp[i-1].v+a[i]==max(dp[i-1].v+a[i],a[i])){
        dp[i].v=dp[i-1].v+a[i];
        dp[i].h=dp[i-1].h;
        dp[i].t=i;
    }
    else if(a[i]==max(dp[i].v+a[i],a[i])){
        dp[i].v=a[i];
        dp[i].h=i;
        dp[i].t=i;
    }
    //printf("%d%d%d\n",dp[i].v,dp[i].h,dp[i].t);
}
