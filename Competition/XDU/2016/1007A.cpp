#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
typedef long long LL;
priority_queue<LL,vector<LL>,greater<LL> > q;
int main()
{
    long long n,k,x,now,ans,num,nn,sum,time,number,rem,ma;
    while(scanf("%lld%lld",&n,&k)!=EOF){
        while(q.size()){
            q.pop();
        }
        nn=0;
        sum=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&x);
            nn++;
            sum+=x;
            q.push(x);
        }
        if(n==1){
            printf("0\n");
        }
        else{
            if(nn<=k){
                printf("%lld\n",sum);
                continue;
            }
            rem=nn%(k-1);//第一个留的数要能使后面每次都能取k个
            if(rem==1){
                rem=k;
            }
            else if(rem==0){
                rem=k-1;
            }
            now=0;
            ans=0;
            num=1;
            while(num<=rem){
                now+=q.top();
                q.pop();
                num++;
            }
            q.push(now);
            ans+=now;
            while(!q.empty()){
                now=0;
                num=1;
                while(num<=k){
                    now+=q.top();
                    q.pop();
                    num++;
                }
                ans+=now;//cout<<now<<' '<<ans;
                if(q.size()!=0){
                    q.push(now);
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
