#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int n,k,num,i,j;
    double q,ans;
    bool point;
    char t[10000],c;
    double p[10000];
    double dp[100000];
    double sum[4];
    double summ[35];
    while(scanf("%lf%d",&q,&n)!=EOF){
        memset(summ,0,sizeof(summ));
        memset(dp,0,sizeof(dp));
        if(n==0)break;
        //printf("%lf %d\n",q,n);
        k=0;
        while(++k<=n){
            //printf("%d",k);
            for(i=1;i<=4;i++){
                sum[i]=0;
            }
            //printf("%lf %lf %lf\n",sum[1],sum[2],sum[3]);
            scanf("%d",&num);
            point=true;
            for(i=1;i<=num;i++){//处理发票
                scanf(" %c:%lf",&t[i],&p[i]);
                //printf("%lf",p[i]);
                if(t[i]!='A'&&t[i]!='B'&&t[i]!='C')point=false;
                if(t[i]=='A'){
                    sum[1]+=p[i];
                    if(sum[1]>600)point=false;
                }
                if(t[i]=='B'){
                    sum[2]+=p[i];
                    if(sum[2]>600)point=false;
                }
                if(t[i]=='C'){
                    sum[3]+=p[i];
                    if(sum[3]>600)point=false;
                }
            }
            //printf("%lf %lf %lf\n",sum[1],sum[2],sum[3]);
            if(point){
                summ[k]=sum[1]+sum[2]+sum[3];
                if(summ[k]>1000)summ[k]=0;
            }
            //printf("%.2lf\n",summ[k]);
        }
        for(i=1;i<=n;i++){
            for(j=n;j>=1;j--){
                if(dp[j-1]+summ[i]<=q){
                    dp[j]=max(dp[j-1]+summ[i],dp[j]);//01背包选或者不选
                }
                //printf("%lf",dp[i]);
            }
        }
        ans=0;
        for(i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
