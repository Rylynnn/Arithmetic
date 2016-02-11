/*贪心策略有误*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct d{
    int day;
    int score;
}dp[1010];
bool com(d i,d j){//保证分数值最大的放在前面
    if(i.score==j.score){
        return i.day<j.day;
    }
    else return i.score>j.score;
}
int main()
{
    int t,n,i,j,sum,s;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            memset(dp,0,sizeof(dp));
            sum=0;
            s=0;
            scanf("%d",&n);
            for(i=1;i<=n;i++){
                scanf("%d",&dp[i].day);
            }
            for(i=1;i<=n;i++){
                scanf("%d",&dp[i].score);
                sum+=dp[i].score;
            }
            sort(dp+1,dp+n+1,com);
            int p[1010];
            memset(p,0,sizeof(p));
            for(i=1;i<=n;i++){//从分数值最大的开始安排天数，尽可能使其最后完成
                for(j=dp[i].day;j>0;j--){
                    if(p[j]==0){
                        p[j]=1;
                        //printf("%d ",j);
                        break;
                    }
                }
                if(j==0){
                    s+=dp[i].score;
                }
            }
            printf("%d\n",s);
        }
    }
    return 0;
}


