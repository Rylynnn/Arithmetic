#include <cstdio>
bool
int main()
{
    int t;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d%d",n,m);
            if((n+1)>>1){
                aver=(n>>1)*(n+1);
                if(aver%m!=0){
                    printf("NO\n");
                }
            }
            else{
                aver=((n+1)>>1)*n;
                if(aver%m!=0){
                    printf("NO\n");
                }
            }
        }
    }
}
