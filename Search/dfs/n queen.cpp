#include<cstdio>
int point;
int sum;
int que(int row,int l,int r){//
    int pos=point&~(row|l|r);//pos为可填入皇后的标记，1为可填，0为不可；
    int p;
    if(row!=point){//当row为point时则无法填皇后
        while(pos!=0){
            p=pos&-pos;//p表示当前状态下皇后填的位置
            pos-=p;//更新pos下一步可填入皇后的位置
            que(row+p,(l+p)<<1,(r+p)>>1);
        }
    }
    else sum++;
}
int main(){
    int n,i;
    int queen[20];
    for(i=1;i<=12;i++){
        sum=0;
        point=(1<<i)-1;
        que(0,0,0);
        queen[i]=sum;
    }
    while(scanf("%d",&n)!=EOF&&n!=0){
        printf("%d\n",queen[n]);
    }
    return 0;
}
