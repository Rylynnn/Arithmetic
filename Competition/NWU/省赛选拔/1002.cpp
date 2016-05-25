#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int a[35],c[35],t,b;
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    a[1]=1;
    c[1]=1;
    for(int i=2;i<=32;i++){
        a[i]=(a[i-1]+1)*2-1;
        c[i]=c[i-1]*2;
        //cout<<a[i]<<' ' <<c[i];
        if(a[i]>1000000000){
            break;
        }
    }
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&b);
            for(int i=1;i<=32;i++){
                if(a[i]>b){
                    if(b-a[i-1]>c[i-1]){
                        printf("%d %d\n",i,b-a[i-1]);
                    }
                    else{
                        printf("%d %d\n",i-1,c[i-1]);
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
