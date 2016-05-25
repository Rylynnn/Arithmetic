#include <bits/stdc++.h>
using namespace std;
double judge(int a){
    if(a>=60&&a<=69){
        return 2.0;
    }
    else if(a>=70&&a<=74){
        return 2.5;
    }
    else if(a>=75&&a<=79){
        return 3.0;
    }
    else if(a>=80&&a<=84){
        return 3.5;
    }
    else if(a>=85&&a<=100){
        return 4.0;
    }
}
double dp[101][1001][11],tmp,ans;
int main()
{
    int n,t,avg,sum,now;

    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d%d",&avg,&n);
            sum=avg*n;
            now=n;
            memset(dp,0,sizeof(dp));
            for(int i=60;i<=100;i++){
                tmp=judge(i);
                for(int v=i;v<=sum;++v){
                    for(int k=1;k<=n;k++){
                        if(v-k*i>=0&&now-k>=0){
                            dp[i][v][n]=max(dp[i][v][n],dp[i-1][v-k*i][n-k]+k*tmp);
                            printf("%.6lf\n",dp[i][v][n]);
                        }
                        else
                            break;
                    }
                    ans=max(ans,dp[i][sum][n]);
                }
            }
            printf("%.6lf\n",dp[100][sum][n]);
        }
    }
}
