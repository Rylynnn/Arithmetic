#include <stdio.h>
int main()
{
    long long a[43];
    int n,i;
    a[1]=1;
    a[2]=2;
    for(i=3;i<=40;i++){
        a[i]=a[i-1]+a[i-2];
    }
    while(scanf("%d",&n)!=EOF){
        printf("%I64d\n",a[n-1]);
    }
    return 0;
}
