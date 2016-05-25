#include <cstdio>
int main(){
    int t,a,b;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d%d",&a,&b);
            if(a%2==1||b%2==1){
                printf("1\n");
            }
            else{
                printf("2\n");
            }
        }
    }
    return 0;
}
