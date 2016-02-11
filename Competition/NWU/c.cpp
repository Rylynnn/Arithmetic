#include<cstdio>
int dfs(int i){
    int sum=0;
    int num,t,j;
    int k=i;
    while(i>0){
        num=1;
        t=i%10;
        for(j=2;j<=t;j++){
            num*=j;
        }
        sum+=num;
        if(sum>k)return 0;
        i/=10;
    }
    //printf("%d\n",sum);
    if(sum==k){//printf("%d\n",sum);
        return 1;
    }
    return 0;
}
int main()
{
    int i;
    for(i=1;i<=40586;i++){
        if(dfs(i)==1){
            //printf("1111");
            printf("%d\n",i);
        }
    }
    return 0;
}
