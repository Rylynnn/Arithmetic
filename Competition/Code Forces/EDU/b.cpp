#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,now,i;
    long long ans;
    int k[10][7]={{1,1,1,0,1,1,1},{0,0,0,0,0,1,1},{0,1,1,1,1,1,0},{0,0,1,1,1,1,1},{1,0,0,1,0,1,1},{1,0,1,1,1,0,1},{1,1,1,1,1,0,1},{0,0,1,0,0,1,1},{
    1,1,1,1,1,1,1},{1,0,1,1,1,1,1}};
    int num[10]={6,2,5,5,4,5,6,3,7,6};
    while(scanf("%d%d",&a,&b)!=EOF){
        ans=0;
        now=a;
        while(now<=b){
            c=now;
            while(c){
                ans+=num[c%10];
                c/=10;
            }
            now++;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
