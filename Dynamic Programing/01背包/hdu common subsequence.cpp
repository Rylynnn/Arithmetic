/*最长公共子序列*/
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#define N 20000
using namespace std;
int dp[N][N];
int main()
{
    string a,b;
    int i,j;
    while(cin>>a>>b){
         for(i=0;i<a.size();i++){
            for(j=0;j<b.size();j++){
                dp[i][j]=0;
            }
         }
        for(i=0;i<a.size();i++){
            for(j=0;j<b.size();j++){
                if(a[i]==b[j]){//两个相等的话（从上一段的i-1和j-1更新
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else if(a[i]!=b[j]){//两个不想等的话（取比他小的两个子序列中较大的值
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        printf("%d\n",dp[a.size()][b.size()]);
    }
    return 0;
}
