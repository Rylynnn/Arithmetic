#include<iostream>
#include<cstdio>
#include<cstring>
#include <cmath>
#define inf 10000000000LL
#define MAX 6007
#define ll long long
using namespace std;
int main()
{
    int a,b[200007],now,sum;
    while(scanf("%d",&a)!=EOF){
        sum=0;
        for(int i=0;i<a;i++){
            scanf("%d",&b[i]);
            sum=sum^b[i];
        }
        if(sum==0){
            printf("No\n");
        }
        else{
            printf("Yes\n");
            for(int i=0;i<a;i++){
                now=sum^b[i];
                if(now<b[i]){
                    printf("%d %d\n",b[i],now);
                }
            }
        }
    }
    return 0;
}
