#include <cstdio>
int main()
{
    int t,a,b,c,x,y,z;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d%d%d",&x,&y,&z);
            a=x-z+y;
            b=z+x-y;
            c=z-x+y;
            if(a%2==0&&b%2==0&&c%2==0){
                printf("%d %d %d\n",a/2,b/2,c/2);
            }
            else{
                printf("Impossible\n");
            }
        }
    }
    return 0;
}
