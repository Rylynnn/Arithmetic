#include<cstdio>
int main()
{
    int k,n,w;
    scanf("%d%d%d",&k,&n,&w);
    int now=0;
    now=k*((1+w)*w/2);
    if(now>n){
        printf("%d",now-n);
    }
    else printf("0");
}
