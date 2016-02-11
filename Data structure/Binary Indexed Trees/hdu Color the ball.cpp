#include<cstdio>
int c[100010];
int t;
int lowbit(int x){
    return x&(-x);
}
void update(int bit,int a){
    while(bit<=t){
        c[bit]+=a;
        bit+=lowbit(bit);
    }
}
int getsum(int x){
    int sum=0;
    while(x>0){
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int i,a,b;
    while(scanf("%d",&t)!=EOF&&t){
        for(i=1;i<=t;i++){
            c[i]=0;
        }
        for(i=1;i<=t;i++){
            scanf("%d%d",&a,&b);
            update(a,1);
            update(b+1,-1);
        }
        printf("%d",getsum(1));
        for(i=2;i<=t;++i)
            printf(" %d",getsum(i));
        printf("\n");
    }
    return 0;
}
