#include<stdio.h>
#include<string.h>

int main()
{
    #ifdef LOCAL
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif // LOCAL
    int a[50],i,m;
    memset(a,0,50);
    a[0]=0;a[1]=1;
    for(i=2;i<50;i++)
       a[i]=a[i-1]+a[i-2];
    while(scanf("%d",&m)!=EOF){
            printf("%d\n",a[m]);
    }
    return 0;
}
