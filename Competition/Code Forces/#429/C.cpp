/*************************************************************************
    > File Name: C.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月18日 星期五 23时55分04秒
 ************************************************************************/
#include <bits/stdc++.h>
using namespace std;
struct node{
    int num, ran;
}a[200007], b[200007];
bool cmp(node a, node b){
    return a.num < b.num;
}
bool cmp2(node a, node b){
    return a.num > b.num;
}
bool cmp3(node a, node b){
    return a.ran < b.ran;
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i].num);
        a[i].ran = i;
    }
    sort(a+1, a+n+1, cmp);
    for(int i=1; i<=n; i++){
        scanf("%d", &b[i].num);
        b[i].ran = i;
    }
    sort(b+1, b+1+n, cmp2);
    for(int i=1; i<=n; i++){
        b[i].num = a[i].num;
    }
    sort(b+1, b+1+n, cmp3);
    cout << b[1].num;
    for(int i=2; i<=n; i++){
        cout << ' ' << b[i].num;
    }
    return 0;
} 
