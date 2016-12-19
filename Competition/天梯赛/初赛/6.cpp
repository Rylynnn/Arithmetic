#include <cstdio>
int main()
{
    int n,c,d,a;
    while(scanf("%d",&n)!=EOF){
        c=0;d=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(a%2==0){
                c++;
            }
            else{
                d++;
            }
        }
        printf("%d %d\n",d,c);
    }
    return 0;
}
