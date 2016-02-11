#include <bits/stdc++.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        while(n){
            if(n/5>0){
                ans+=n/5;
                n=n%5;
                continue;
            }
            else if(n-4>=0){
                n=n-4;
                ans++;
                continue;
            }
            else if(n-3>=0){
                n=n-3;
                ans++;
                continue;
            }
            else if(n-2>=0){
                n=n-2;
                ans++;
                continue;
            }
            else if(n-1>=0){
                n=n-1;
                ans++;
                continue;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
