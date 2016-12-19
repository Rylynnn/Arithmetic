#include <bits/stdc++.h>
int main()
{
    long long t,s,x;
    while(scanf("%I64d%I64d%I64d",&t,&s,&x)!=EOF){
        if(((x-t)/s>=0&&(x-t)%s==0)||((x-t-1)/s>0&&(x-t-1)%s==0)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

}
