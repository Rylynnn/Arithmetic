#include <bits/stdc++.h>
#define eps 1e-6
#define MAX 100007
#define ll long long
using namespace std;
int magic,n,m,ob,a[MAX],ans[400][15][10];
void init(){
    magic=sqrt(n);
    int u;
    for(int i=1;i<=n;i++){
        u=i/magic;
        int now=a[i];
        for(int j=1;j<=12;j++){
            ans[u][j][now%10]++;
            now/=10;
        }
    }
}
int query(int x,int y,int d,int p){
    int sum=0;
    for(int i=x;i<=y;){
        if(i%magic==0&&i+magic-1<=y){
            sum+=ans[i/magic][d][p];
            i+=magic;
        }
        else{
            int now=a[i];
            for(int j=1;j<=12;j++){
                if(j==d&&(now%10==p)){
                    sum++;
                    break;
                }
                if(j>d){
                    break;
                }
                now/=10;
            }
            i++;
        }
    }
    return sum;
}
int main()
{
    int t,x,y,d,p;
    char ob;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        init();
        for(int i=0;i<m;i++){
            scanf(" %c",&ob);
            if(ob=='Q'){
                scanf("%d%d%d%d",&x,&y,&d,&p);
                printf("%d\n",query(x,y,d,p));
            }
            else if(ob=='S'){
                scanf("%d%d",&x,&y);
                int now=a[x];
                a[x]=y;
                for(int j=1;j<=12;j++){
                    ans[x/magic][j][now%10]--;
                    now/=10;
                }
                for(int j=1;j<=12;j++){
                    ans[x/magic][j][y%10]++;
                    y/=10;
                }
            }
        }
    }
    return 0;
}
