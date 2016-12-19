#include <cstdio>
using namespace std;
int main()
{
    int a;
    scanf("%d",&a);
    if(a+2==7){
        printf("7\n");
    }
    else{
        printf("%d\n",(a+2)%7);
    }
    return 0;
}
