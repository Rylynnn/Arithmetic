#include <stdio.h>

int main()
{
    int w,a[9],b[9],mmax,result1,result2,i,can;
    while(scanf("%d",&w)!=EOF){
        can=0;
        result2=0;
        for(i=0;i<9;++i){
            scanf("%d",&a[i]);
            if(a[i]<=w)
                can=1;
            b[i]=w/a[i];
        }
        if(can==0){
            printf("-1\n");
            continue;
        }
        mmax=b[8];
        result1=9;
        for(i=7;i>=0;--i)
            if(b[i]>mmax){
                mmax=b[i];
                result1=i+1;
            }
        w=w-mmax*a[result1-1];
        for(i=0;i<9;++i){
            if(i>result1-1&&a[i]-a[result1-1]<=w)
                result2=i+1;
        }
        if(result2!=0){
            while(w>=a[result2-1]-a[result1-1]){
                printf("%d",result2);
                --mmax;
                w=w-a[result2-1]+a[result1-1];
            }
        }
        while(mmax!=0){
            printf("%d",result1);
            --mmax;
        }
        printf("\n");
    }
}
