#include <cstdio>
int main()
{
    int n,ans,p=0;
    scanf("%d",&n);
    ans=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            p=1;
            break;
        }
    }
    //printf("%d",p);
    if(p==1){
        for(int i=3;i<n;i++){
            if(n%i==0){
                ans=i;
                break;
            }
        }
    }
    printf("%d\n",ans-1);
    return 0;
}
