/*
多阶树状数组更新求和时候需要重新定义变量储存第二个第三个变量值的初始值
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define N 100010
using namespace std;
int bitx[N],bity[N];
int n,m;
int lowbit(int x){
    return x&(-x);
}
void update(int x,int y){
    int a;
    while(x<=n){
        bitx[x]++;
        x+=lowbit(x);
    }
    while(y<=m){
        bity[y]++;
        y+=lowbit(y);
    }
}
int getsum(int x,int y,int x1,int y1){
    int sum=0,sum1=0,a;
    while(x>0){
        sum+=bitx[x];
        x-=lowbit(x);
    }
    while(x1>0){
        sum1+=bitx[x1];
        x1-=lowbit(x1);
    }
    if((sum1-sum+1)==(x1-x+1)){
        return true;
    }
    else{
        while(y>0){
            sum+=bity[y];
            y-=lowbit(y);
        }
        while(y1>0){
            sum+=bity[y1];
            y1-=lowbit(y1);
        }
        if((sum1-sum+1)==(x1-x+1)){
            return true;
        }
    }
    //printf("%d",sum);
    return false;
}
int main()
{
    int x,y,q,i,j,k,x1,y1,x2,y2;
    int t;
    bool ans;
    scanf("%d",&x);
    while(x--){
        scanf("%d%d%d%d",&n,&m,&k,&q);
        memset(bitx,0,sizeof(bitx));
        memset(bity,0,sizeof(bity));
        for(i=1;i<=k;i++){
            scanf("%d%d",&x,&y);
            update(x,y);
        }
        for(i=1;i<=q;i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            ans=getsum(x1,y1,x2,y2);
            if(ans){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
    return 0;
}
