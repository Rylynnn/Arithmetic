#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    int x;
    scanf("%d",&x);
    int ans=0;
    while(x){
        if((x&1)==1){
            ans++;
        }
        //printf("%d",ans);
        x=x>>1;
    }
    printf("%d\n",ans);
}
