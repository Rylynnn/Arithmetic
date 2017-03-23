#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[220];
long long dp[220][220];
int main()
{
    int n;
    cin >> n;
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i + n] = a[i];
        }
        memset(dp, 0, sizeof(dp));
        int l = 2 * n;
        for (int len = 1; len< n;len++)
        for (int i = 1; i + len <= l; i++)
        {
            int j = i + len;
            for (int k = i; k < j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i] * a[k+1] * a[j+1]);
        }
        long long MAX = 0;
        for (int i = 1; i <= n;i++)
            MAX = max(MAX, dp[i][i+n-1]);
        cout << MAX << endl;
    }
    return 0;
}
