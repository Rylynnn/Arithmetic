#include <bits/stdc++.h>
#define eps 1e-6
#define INF 0x3f3f3f3f
int main()
{
    int a,b,x,y,v;
    while(scanf("%d%d",&a,&b)!=EOF){
        int n;
        scanf("%d",&n);
        double ans=INF;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&v);
            double now;
            now=sqrt((x-a)*(x-a)+(y-b)*(y-b))/v;
            if(ans-now>eps){
                ans=now;
            }
        }
        printf("%.12f\n",ans);
    }
}
