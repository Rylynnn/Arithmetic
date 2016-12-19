#include <cstdio>
int main()
{
    int a[15],n;
    a[0]=1;
    for(int i=1;i<15;i++){
        a[i]=a[i-1]*2;
    }
    scanf("%d",&n);
    printf("2^%d = %d",n,a[n]);
    return 0;
}
