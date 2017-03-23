#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#define ll long long
using namespace std;
string s;
string a,b;
int dp[1009][1009],ans;
int main()
{
    cin>>a>>b;
    memset(dp,0,sizeof(dp));
    ans=0;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            if(ans<dp[i][j]){
                ans=dp[i][j];
            }
        }
    }
    int lena,lenb;
    lena=a.size();
    lenb=b.size();
    while (lena&&lenb) {
        if (dp[lena][lenb]==dp[lena][lenb-1]) lenb--;
        else if (dp[lena][lenb]==dp[lena-1][lenb]) lena--;
        else {
            s.push_back(a[lena-1]);
            lena--;lenb--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
