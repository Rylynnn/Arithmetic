/*************************************************************************
    > File Name: 1004.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月19日 星期六 13时50分07秒
 ************************************************************************/
#include <bits/stdc++.h>
#define N 1000007
#define MOD 1000000007
using namespace std;
int next[N];
char a[N],b[N], ans;
void kmp(char *tem){//打表表示在第i个字符之前字符串tem前缀相同的真子后缀
    int ts=strlen(tem);
    next[0]=-1;
    int point=-1;
    int t=0;
    while(t<ts){
        if(point==-1||tem[point]==tem[t]){
            ++t;
            ++point;
            if(tem[t]!=tem[point])
                next[t]=point;
            else next[t]=next[point];
        }
        else point=next[point];
    }
}
void findl(char *tem,char *main){//查找模板串在主串中的最大公共子串长度，返回主串中的位置
    int tstr=strlen(tem);
    int mstr=strlen(main);
    int i=0,j,top=0;//top存储每次匹配时候主串的开始位置
    j=top;
    while(i<tstr && j < mstr){
        if(j == -1 || tem[i] == main[j]){
            i++;
            j++;
            if(i == tstr || j == mstr){
                ans += i * (i + 1) / 2 % MOD;
                ans %= MOD;
                i = 0;
            }
        }
        else if{
            if(i != 0){
                ans += i * (i + 1) / 2 % MOD;
                ans %= MOD;
            }
            j = next[j];
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
        memset(next, 0, sizeof(next));
        scanf("%s%s",a,b);
        reverse(a, a+strlen(a));
        reverse(b, b+strlen(b));
        kmp(b);
        findl(b, a);
        printf("%d\n", ans % MOD);
    }
    return 0;
}
