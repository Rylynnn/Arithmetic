#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,m,x,y,sum,g,up;
    int a[107],p[107];
    scanf("%d",&t);
    while(t-->0){
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            a[x]=y;
            p[x]=1;
        }
        if(p[1]==0){
            a[1]=100;
        }
        else if(p[2]==0){
            a[2]=a[1];
            p[2]=1;
        }
        if(p[2]==0){
            a[2]=100;
        }
        int now=3;
        for(int i=3;i<=n;i++){
            if(p[i]==1){
                for(int j=now;j<i;j++){
                    a[j]=a[i];
                }
                now=i+1;
            }
        }
        sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
        }
        up=a[1]+a[2];
        g=__gcd(up,sum);
        printf("%d/%d\n",up/g,sum/g);
    }
    return 0;
}
