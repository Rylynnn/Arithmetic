/*
T1:dfs中j的循环没有break出去。
*/
#include <bits/stdc++.h>
#define MAX 0x3f3f3f3f
using namespace std;
int ans;
int vis[13],a[13];
void dfs(int cnt,int sum){
    if(sum>ans){
        return;
    }
    if(cnt==10){
        ans=sum;
        //printf("%d ",ans);
        return;
    }
    for(int i=1;i<=10;i++){//每个点都可能开始，这样可以做出所有的可能性(全排列思想)
        if(!vis[i]){
            vis[i]=1;
            for(int j=i+1;j<=10;j++){
                if(!vis[j]){
                    dfs(cnt+1,sum+fabs(a[i]-a[j]));
                    break;
                }
            }
            vis[i]=0;//回溯
        }
    }
}
int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--){
        for(int i=1;i<=10;i++){
            scanf("%d",&x);
            a[x]=i;
        }
        memset(vis,0,sizeof(vis));
        ans=MAX;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
