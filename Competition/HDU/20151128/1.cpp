#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,i,ans,num,q;
    while(scanf("%d%d%d%d",&n,&a,&b,&c)!=EOF){
        ans=0;
        q=0;
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            q+=num;
            if(q>=a&&q<b){
                ans+=2;
                q=0;
            }
            else if(q>=b&&q<c){
                ans+=3;
                q=0;
            }
            else if(q>=c){
                ans+=4;
                q=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
