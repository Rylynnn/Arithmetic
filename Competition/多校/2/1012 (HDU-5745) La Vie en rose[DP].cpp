#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m;
bool dp[5005];//dp[j]表示能匹配到串p[j]
char s[100005],p[5005];
char ans[100005];

char solve(int i) {
    int j=0;
    memset(dp,false,sizeof(dp));
    if(s[i]==p[j]) {
        dp[j]=true;
        ++i;
        ++j;
    }
    else if(s[i]==p[1]&&s[i+1]==p[j]) {
        dp[j+1]=true;
        i+=2;
        j+=2;
    }
    else {
        return '0';
    }
    for(;i<n&&j<m;) {
        if(dp[j-1]&&s[i]==p[j]) {
            dp[j]=true;
            ++i;
            ++j;
        }
        else if(dp[j-1]&&s[i]==p[j+1]&&s[i+1]==p[j]) {
            dp[j+1]=true;
            i+=2;
            j+=2;
        }
        else {
            return '0';
        }
    }
    return dp[m-1]?'1':'0';
}

int main() {
    int T;
    scanf("%d",&T);
    while(T-->0) {
        scanf("%d%d",&n,&m);
        scanf("%s%s",s,p);
        for(int i=0;i<n;++i) {
            ans[i]=solve(i);
        }
        ans[n]='\0';
        printf("%s\n",ans);
    }
}
