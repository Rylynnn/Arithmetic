#include <bits/stdc++.h>
int main()
{
    int n;
    int a[7],ans;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<7;i++){
            scanf("%d",&a[i]);
        }
        int i;
        int p;
        p=0;
        while(n>0){
            for(i=0;i<7;i++){
                if(n-a[i]>0){
                    n-=a[i];
                }
                else{
                    p=1;
                    break;
                }
            }
            if(p==1){
                ans=i+1;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
