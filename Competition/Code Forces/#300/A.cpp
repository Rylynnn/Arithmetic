/*本身没想清楚唉。。。每次暴力枚举删掉中间之后的情况是否可以符合
WA1：没考虑可能出现CODEFORCE的情况
*/
#include <bits/stdc++.h>
using namespace std;
string bas="CODEFORCES";
string a;
int len;
bool check(int beg){
    int num=0;
    for(int i=0;i<len;i++){
        if(i>=beg&&i<=beg+len-10-1){
            continue;
        }
        if(a[i]!=bas[num]){
            return 0;
        }
        num++;
    }
    return 1;
}
int main()
{
    int p=0;
    while(cin>>a){
        len=a.size();
        p=0;
        if(len<10){
            p=1;
            printf("NO\n");
        }
        for(int i=0;i<len;i++){
            if(check(i)&&p==0){
                p=1;
                printf("YES\n");
            }
        }
        if(p==0){
            printf("NO\n");
        }
    }
    return 0;
}
