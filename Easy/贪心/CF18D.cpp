/*************************************************************************
    > File Name: G.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月02日 星期三 01时11分52秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int a, b;
}num[5009];
int se[2007], vis[5009], ans[1007],tmp;
void get_set(){
    for(int i=0; i<tmp; i++){
        if(ans[i] > 9){
            ans[i + 1] += ans[i]/10;
            ans[i] %= 10;
        }
    }
    while(ans[tmp] > 9){
        ans[tmp + 1] = ans[tmp] / 10;
        ans[tmp] %= 10;
        tmp++;
    }
}
int main(){
    memset(se, -1, sizeof(se));
    int n, x;
    string s;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        cin >> s >> x;
        if(s == "sell"){
            se[x] = i;
            num[i].a = 0;
            num[i].b = x;
        }
        else{
            num[i].a = 1;
            num[i].b = x;
        }
    }
    for(int i=2000; i>=0; i--){
        for(int j=0; j<=tmp; j++){
            ans[j] <<= 1;
        }
        get_set();
        if(se[i] >= 0){
            int j;
            for(j=se[i]; j>=0; j--){
                if(vis[j]){
                    break;
                }
                if(num[j].a == 1 && num[j].b == i){
                    break;
                }
            }
            if(j >= 0 && !vis[j]){
                for(; j<=se[i]; j++){
                    vis[j]=1;
                }
                ans[0]++;
                get_set();
            }
        }
    }
    for(int i=tmp; i>=0; i--){
        printf("%d", ans[i]);
    }
    cout << endl;
    return 0;
}
