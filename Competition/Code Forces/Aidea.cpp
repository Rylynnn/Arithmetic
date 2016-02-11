#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int n,k,days[105],dp[10005],tmp;


int main()
{
    while(2==scanf("%d%d",&n,&k)) {
        for(int i=0;i<n;++i)
            scanf("%d",&days[i]);
        memset(dp,0,sizeof(dp));
        vector<int> index[10005];
        for(int i=0;i<n;++i) {
            for(int j=k;j>=days[i];--j) {
                if(dp[j]<(tmp=dp[j-days[i]]+1)) {
                    dp[j]=tmp;
                    index[j]=index[j-days[i]];
                    index[j].push_back(i);
                }
            }
        }
        printf("%d\n",dp[k]);
        if(0!=index[k].size()) {
            printf("%d",index[k][0]+1);
            for(int i=1;i<index[k].size();++i) {
                printf(" %d",index[k][i]+1);
            }
        }
    }
    return 0;
}
