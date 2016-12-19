/*
LANG:C++
ID:15829681
TASK:prefix
*/
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string a,b,m[207];
int n,len;
int dp[200007];
bool judge(int x,int y){
    int p=0;
    if(m[y].size()>b.size()-x){
        p=1;
    }
    else{
        for(int i=x;i<x+m[y].size();i++){
            if(m[y][i-x]!=b[i]){
                p=1;
            }
        }
    }
    if(p==0){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    int ans,next;
    n=0;
    while(getline(cin,a)){
        if(a=="."){
            break;
        }
        memset(dp,0,sizeof(dp));

        //cout<<a<<endl;
        int i;
        for(i=0;i<a.size();){
            while(a[i]!=' '&&i<a.size()){
                m[n].push_back(a[i]);
                i++;
            }
            i++;
            n++;
            //cout<<n<<i<<endl;
        }
    }
    string c;
        while(getline(cin,c)){
            b+=c;
        }
        len=b.size();
        int now=0;
        ans=0;
        dp[0]=1;
        //cout<<n<<endl;
        while(now<=ans&&now<len){
            if(dp[now]){
                for(int i=0;i<n;i++){
                    next=now+m[i].size();
                    if(dp[next]==0&&judge(now,i)){
                        dp[next]=1;//如果下一个往后延伸之后的长度可以到达则标记为新的可以开始延伸的点
                        ans=max(ans,next);
                        //cout<<now<<' '<<i;
                    }
                }
            }
            now++;
        }
        //cout<<ans<<' '<<len;
        printf("%d\n",min(ans,len));
    return 0;
}
