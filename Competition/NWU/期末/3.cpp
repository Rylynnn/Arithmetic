#include <stdio.h>
#define N 100007
int fun(int m,int k,int i){
    if(i==1){
        return (m+k-1)%m;
    }
    else{
        return (fun(m-1,k,i-1)+k)%m;
    }
}
int main()
{
    int n,m,num,k,i;
    int a[N];
    int number;
    while(scanf("%d%d",&n,&m)!=EOF) {
        for(i=1;i<=n;i++){
            printf("%d    ",fun(n,m,i)+1);
        }
        printf("\n");
        //printf("%d\n",fun(n,m,n)+1);
    }
    return 0;
}
