#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,a;
    int p=0;
    long long ans=0;
    long long num;
    while(scanf("%d",&n)!=EOF){
        ans=1;
        p=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            if(p==0&&a==1){
                p=1;
                num=0;
            }
            else if(p==1&&a==0){
                num++;
            }
            else if(p==1&&a==1){
                ans*=num+1;
                num=0;
                //printf("%d",ans);
            }
        }
        if(p==0){
            printf("0\n");
        }
        else{
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
