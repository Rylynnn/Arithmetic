#include <bits/stdc++.h>
#define eps 1e-6
#define INF 1e18
#define ll long long
using namespace std;
int magic,n,a[50007],ans[50007],block[50007];
void init(int n){
    magic=sqrt(n);
    int u;
    for(int i=1;i<=n;i++){
        u=i/magic;
        block[i]=u;
        ans[u]+=a[i];
    }
}
int query(int x,int y){
    int sum=0;
    for(int i=x;i<=y;){
        if(i%magic==0&&i+magic-1<=y){
            sum+=ans[block[i]];
            i+=magic;
        }
        else{
            sum+=a[i];
            i++;
        }
    }
    return sum;
}
int main()
{
    int t,x,y;
    char obey[10];
    scanf("%d",&t);
    int kase=0;
    while(t--){
        kase++;
        scanf("%d",&n);
        memset(ans,0,sizeof(ans));//wa没有初始化
        memset(block,0,sizeof(block));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        init(n);
        printf("Case %d:\n",kase);
        while(scanf("%s",obey)){
            if(obey[0]=='E'){
                break;
            }
            scanf("%d%d",&x,&y);
            if(obey[0]=='Q'){
                printf("%d\n",query(x,y));
            }
            else if(obey[0]=='A'){
                ans[block[x]]+=y;
                a[x]+=y;//必须要记得更改本来的值
            }
            else if(obey[0]=='S'){
                ans[block[x]]-=y;
                a[x]-=y;
            }
        }
    }
    return 0;
}
