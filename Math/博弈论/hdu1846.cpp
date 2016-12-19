#include <bits/stdc++.h>
int main()
{
    int t;
    scanf("%d",&t);
    int n,m;
    while(t--){
        scanf("%d%d",&n,&m);
        if(n%(m+1)==0){
            printf("second\n");
        }
        else{
            printf("first\n");
        }
    }
    return 0;
}
