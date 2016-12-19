#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,ans,a;
    while(scanf("%d%d",&n,&m)!=EOF){
        ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(a>m){
                ans+=2;
            }
            else{
                ans+=1;
            }
        }
        printf("%d\n",ans);
    }
}
