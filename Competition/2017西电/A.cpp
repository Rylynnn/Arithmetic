#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n,p,k,x,len;
int dp[50][207];
string a,s,dic[10];
bool match(int b,int e,int ee){
    int l=dic[e].size();
    if(l+b-1>ee){
        return false;
    }
    for(int i=0;i<l;i++){
        if(s[i+b]!=dic[e][i]){
            return false;
        }
    }
    return true;
}
int cal(int b,int e){
    int ans=0;
    for(int i=b;i<=e;i++){
        for(int j=0;j<x;j++){
            if(match(i,j,e)){
                ans++;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    while(n--){
        memset(dp,0,sizeof(dp));
        a.clear();
        s.clear();
        scanf("%d%d",&p,&k);
        for(int i=0;i<p;i++){
            cin>>a;
            s+=a;
        }
        scanf("%d",&x);
        for(int i=0;i<x;i++){
            cin>>dic[i];
        }
        len=s.size();
        for(int i=1;i<=k;i++){
            for(int j=0;j<len;j++){
                for(int k=0;k<j;k++){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+cal(k+1,j));
                    //cout<<cal(k,j)<<endl;
                }
                if(i==1||i==2)
                cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            }
        }
        //cout<<cal(197,197);
        printf("%d\n",dp[k][len-1]);
    }
}
