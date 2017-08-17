/*************************************************************************
    > File Name: hdu2516.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月05日 星期六 20时04分35秒
 ************************************************************************/
#include <bits/stdc++.h>
#define ll long long
#define N 1e12
using namespace std;
int n;
bool dfs(int n, int now){
    for(int i=1; i<=n; i++){
        if(i <= now){
            if(!dfs(2 * i, now - i)){
                return true;
            }
        }
        else{
            break;
        }
    }
    return false;
}
map<ll, int> p;
ll f[1000000];
void fibbo(){
    f[0] = 1;
    f[1] = 1;
    int i;
    for(i=2; ; i++){
        f[i] = f[i-1] + f[i-2];
        if(f[i] > N){
            break;
        }
    }
    for(int j=2; j<i; j++){
        p[f[j]] = 1;
    }
    return;
}
int main()
{
    fibbo();
    ll a;
    while(scanf("%lld", &a) != EOF){
 //   for(int i=2; i<=n; i++){
 //       int flag = 0;
 //       if(!dfs(i - 1, i)){
 //           flag = 1;
 //       }
 //       if(flag == 0){
 //           printf("%d:First win\n", i);
 //       }
 //       else{
 //           printf("%d:Second win\n", i);
 //       }
 //   }
        if(a == 0){
            break;
        }
        if(p[a] == 1){
            printf("Second win\n");
        }
        else{
            printf("First win\n");
        }
    }
    return 0; 
}//

