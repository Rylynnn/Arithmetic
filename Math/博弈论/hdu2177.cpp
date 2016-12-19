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
    int a,b,k,temp,tmp,tempp;
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a==0&&b==0){
            break;
        }
        if(a>b){
            swap(a,b);
        }
        k=b-a;
        temp=k*((1.0+sqrt(5))/2.0);
        if(a==temp){
            printf("0\n");
        }
        else{
            printf("1\n");
            if(fabs(temp-a)==fabs(temp+k-b)&&temp<a){
                printf("%d %d\n",temp,temp+k);
                tmp=temp;
            }
            if(a==0){
                printf("0 0\n");
            }
            for(int i=1;i<=b;i++){
                temp=i*((1.0+sqrt(5))/2.0);
                if(temp==tmp){
                    continue;
                }
                tempp=temp+i;
                if(temp==a){
                    printf("%d %d\n",a,tempp);
                }
                else if(tempp==a){
                    printf("%d %d\n",temp,a);
                }
                else if(tempp==b){
                    printf("%d %d\n",temp,b);
                }
            }
        }
    }
    return 0;
}
