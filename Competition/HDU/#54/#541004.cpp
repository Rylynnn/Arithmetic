#include <cstdio>
int gcd(int a,int b){
    return (b>0)?gcd(b,a%b):a;
}
int main()
{
    int t,n,num,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        num=0;
        for(i=1;i<=n;i++){
            if(gcd(n+1,i)==1){
                num++;
            }
        }
        printf("%d\n",num);
    }
}
