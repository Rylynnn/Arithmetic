#include<cstdio>
#include<cstring>
#define N 32010
int bit[N];
int lowbit(int x){
    return x&(-x);
}
void update(int x,int a){
    while(x<=N){
        bit[x]+=a;
        x+=lowbit(x);
    }
}
int getsum(int x){
    int sum;
    sum=0;
    while(x>0){
        sum+=bit[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int t,i,x,y;
    int level[N];
    while(scanf("%d",&t)!=EOF){
        memset(level,0,sizeof(level));
        memset(bit,0,sizeof(bit));
        for(i=1;i<=t;i++){
            scanf("%d%d",&x,&y);//因为输入过程中默认y的值为递增，故每次y有增加的时候，x必定与之前的y所对应的x有重叠或者在其范围之内，故直接计算就可。
            level[getsum(++x)]++;//x==1的时候level为0，bit[x]存的是横坐标为x时，x当前管辖范围内的星星数
            update(x,1);
        }
        for(i=0;i<t;i++){
           printf("%d\n",level[i]);
        }
    }
    return 0;
}
