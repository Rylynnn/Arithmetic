#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
int w,l,num,dp[307],ans,len,mn;
string a[607],m;
void judge(int i){
    for(int j=0;j<w;j++){
        num=0;
        for(int k=i-1;k<l;k++){
            if(m[k]==a[j][num]){
                num++;
                if(num==a[j].size()){
                    len=k+1-i+1-a[j].size();
                    if(dp[k+1]>dp[i-1]+len){
                        dp[k+1]=dp[i-1]+len;
                    }
                    break;
                }
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d",&w,&l)!=EOF){
        memset(dp,INF,sizeof(dp));
        cin>>m;
        for(int i=0;i<w;i++){
            cin>>a[i];
        }
        dp[0]=0;
        for(int i=1;i<=l;i++){
            judge(i);
            dp[i]=min(dp[i-1]+1,dp[i]);
        }
        printf("%d\n",dp[l]);
    }
    return 0;
}
