#include <stdio.h>

int main()
{
    int n;
    int num;
    num=1;
    while(scanf("%d",&n)!=EOF){
        num++;
        if(num<=3){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
}
