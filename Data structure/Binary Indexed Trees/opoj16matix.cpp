/*
多阶树状数组更新求和时候需要重新定义变量储存第二个第三个变量值的初始值
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define N 1010
using namespace std;
int n;
int bit[N][N];
int lowbit(int x){
    return x&(-x);
}
void update(int x,int y){
    int a;
    while(x<=n){
        a=y;
        while(a<=n){
            bit[x][a]++;
            a+=lowbit(a);
        }
        x+=lowbit(x);
    }
}
int getsum(int x,int y){
    int sum=0,a;
    while(x>0){
        a=y;
        while(a>0){
            sum+=bit[x][a];
            a-=lowbit(a);
        }
        x-=lowbit(x);
    }
    //printf("%d",sum);
    return sum;
}
int main()
{
    int x,i,j,k,x1,y1,x2,y2;
    int t;
    string obey;
    scanf("%d",&x);
    while(x--){
        scanf("%d%d",&n,&t);
        memset(bit,0,sizeof(bit));
        for(i=1;i<=t;i++){
            cin>>obey;
            scanf("%d%d",&x1,&y1);
            if(obey=="C"){
                scanf("%d%d",&x2,&y2);
                update(x1,y1);
                update(x2+1,y1);
                update(x1,y2+1);
                update(x2+1,y2+1);
                //for(j=1;j<=n;j++){
                  //  for(k=1;k<=n;k++){
                    //    printf("%d",bit[j][k]);
                   // }
                //}
            }
            else{
                printf("%d\n",getsum(x1,y1)&1);
            }
        }
        if(x>0){
            printf("\n");
        }
    }
    return 0;
}
