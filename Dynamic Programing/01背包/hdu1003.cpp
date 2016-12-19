#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct node{
    int len,b,e;
}ans,dp[100007];
int a[100007];
int main()
{
    int t,num,n;
    while(scanf("%d",&t)!=EOF){
        num=0;
        while(num++<t){
            scanf("%d",&n);
            memset(a,0,sizeof(a));
            memset(dp,0,sizeof(dp));
            ans.len=-INF;
            ans.b=ans.e=0;
            for(int i=1;i<=n;i++){
                scanf("%d",&a[i]);
            }
            dp[1].len=a[1];
            dp[1].b=dp[1].e=1;
            for(int i=2;i<=n;i++){
                if(dp[i-1].len<0){
                    dp[i].len=a[i];
                    dp[i].b=i;
                    dp[i].e=i;
                }
                else{
                    if(max(dp[i-1].len+a[i],a[i])==dp[i-1].len+a[i]){
                        dp[i].len=dp[i-1].len+a[i];
                        dp[i].b=dp[i-1].b;
                        dp[i].e=i;//cout<<dp[i].len<<' '<<dp[i].b<<' '<<dp[i].e<<endl;
                    }
                    else{
                        dp[i].len=a[i];
                        dp[i].b=i;
                        dp[i].e=i;
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(ans.len<dp[i].len){
                    ans=dp[i];
                }
            }
            if(num==1){
                printf("Case %d:\n",num);
                printf("%d %d %d\n",ans.len,ans.b,ans.e);
            }
            else{
                printf("\n");
                printf("Case %d:\n",num);
                printf("%d %d %d\n",ans.len,ans.b,ans.e);
            }
        }
    }
}
