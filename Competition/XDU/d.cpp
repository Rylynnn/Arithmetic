#include<cstdio>
int sum[310];
double mi,a;
int n,m,p;
int aver(int x,int y);
int main()
{
    int i,j,t;
    for(i=0;i<=300;i++){
        for(j=0;j<=i;j++){
            sum[i]+=j;
        }
    }
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n<210&&m<=210)printf("stupid\n");
        else{
            mi=0;
            p=0;
            a=0;
            printf("%d\n",aver(m,n));
        }
    }
    return 0;
}
int aver(int x,int y){
    int i;
    int point=0;
    if(a<210){
        a=(mi+(sum[x]-sum[y]+y))/(m-n+1);
        p++;
    }
    if(a>=210)return p;
    for(i=n;i<=m;i++){
        if(i<=a)point++;
        if(i>a)break;
    }
    mi=point*a;
    return aver(x+point-1,y);
}
