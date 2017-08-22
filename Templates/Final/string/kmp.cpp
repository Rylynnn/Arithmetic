/*************************************************************************
    > File Name: kmp.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月19日 星期六 15时05分43秒
 ************************************************************************/
#include <bits/stdc++.h>
#define N 1000007
#define MOD 1000000007
using namespace std;
int f[N];
char a[N],b[N];
long long ans;
void kmp(char *s){//打表表示在第i个字符之前字符串tem前缀相同的真子后缀
    int len = strlen(s);
    for(int i=1;i<len;i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j])
            j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}
void findl(char *s, char *a){//查找模板串在主串中的最大公共子序列长度，返回主串中的位置
    int tstr=strlen(s);
    int mstr=strlen(a);
    int j=0;
    a[mstr] = '*';
    for(int i=0;i<=mstr;i++)
    {
        while(j && a[i]!=s[j]) {
            ans += ((long long)j + 1)*(j)/2;
            ans %= MOD;
            j=f[j];

        }
        if(a[i]==s[j]) {
            j++;
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        ans = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(f, 0, sizeof(f));
        scanf("%s%s",a,b);
        reverse(a, a+strlen(a));
        reverse(b, b+strlen(b));
        kmp(b);
        findl(b, a);
        printf("%I64d\n", ans % MOD);
    }
    return 0;
}
