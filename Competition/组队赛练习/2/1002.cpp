/*
打表，逆向思维，倍数处理转化成质因数打表
wa:b[i]*c[i]本身可能爆long long。。。。。。。。
*/
#include <bits/stdc++.h>
using namespace std;
int a[100007],b[100007],c[100007],vis[100007];
int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(vis[a[i]]){
                b[i]=a[vis[a[i]]];
            }
            else{
                b[i]=a[i];
            }
            for(int j=1;j*j<=a[i];j++){
                if(a[i]%j==0){
                    vis[j]=i;
                    vis[a[i]/j]=i;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        for(int i=n;i>=1;i--){
            if(vis[a[i]]){
                c[i]=a[vis[a[i]]];
            }
            else{
                c[i]=a[i];
            }
            for(int j=1; j*j<=a[i]; j++){
                if(a[i]%j==0){
                    vis[j]=i;
                    vis[a[i]/j]=i;
                }
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++){
            sum+=(long long)b[i]*c[i];
        }
        printf("%I64d\n",sum);
    }
}
