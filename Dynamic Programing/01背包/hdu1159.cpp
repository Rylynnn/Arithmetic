/*
a[i]==b[i]唉。。。傻逼错误错的也是没谁了。。。
*/
#include <bits/stdc++.h>
using namespace std;
int dp[1007][1007];
int main()
{
    string a,b;
    int  alen,blen;
    while(cin>>a>>b){
        memset(dp,0,sizeof(dp));
        alen=a.size();
        blen=b.size();
        for(int i=0;i<alen;i++){
            for(int j=0;j<blen;j++){
                if(a[i]==b[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                    //printf("%d",dp[i+1][j+1]);
                }
                else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
            //printf("\n");
        }
        printf("%d\n",dp[alen][blen]);
    }
    return 0;
}
