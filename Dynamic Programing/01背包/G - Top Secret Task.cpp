#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=155;
const int INF=0x3f3f3f3f;

int n,k,s,ans;
int a[MAXN];
int dp[3][MAXN][MAXN*MAXN/2+5];//dp[i&1][j][l]表示在前i个数选择j个数放在前j个位置且花费为l时的能得到的最小值

int main() {
    while(3==scanf("%d%d%d",&n,&k,&s)) {
        for(int i=1;i<=n;++i) {
            scanf("%d",a+i);
        }
        if(s>=n*(n-1)/2) {//如果移动次数限制允许将最小的k个数放在前k个位置，直接输出，相当于剪枝，其余的状态就可以进行DP
            sort(a+1,a+1+n);
            ans=0;
            for(int i=1;i<=k;++i) {
                ans+=a[i];
            }
            printf("%d\n",ans);
            continue;
        }
        memset(dp,0x3f,sizeof(dp));
        for(int l=0;l<=s;++l) {
            dp[0][0][l]=dp[1][0][l]=0;//一个元素都不选时，元素和为0
        }
        for(int i=1;i<=n;++i) {//枚举可能会选取的元素i
            for(int j=1;j<=i;++j) {//枚举当前数是选取的第j个数
                for(int l=0;l<=s;++l) {//枚举已用的交换次数l
                    dp[i&1][j][l]=dp[(i-1)&1][j][l];//不选元素i
                    if(l>=i-j) {//若已用交换次数大于等于将用的交换次数
                        dp[i&1][j][l]=min(dp[i&1][j][l],dp[(i-1)&1][j-1][l-(i-j)]+a[i]);//选元素i
                    }
                }
            }
        }
        ans=INF;
        for(int i=0;i<=s;++i) {
            ans=min(ans,dp[n&1][k][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
