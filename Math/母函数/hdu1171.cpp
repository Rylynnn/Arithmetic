#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#define inf 10000000000LL
#define MAX 100007
#define MOD 1000000007
#define ll long long
using namespace std;
int t,sum,p,now,ans;
int a[107],b[107],vis[250007];
void func(){
    memset(vis,0,sizeof(vis));
    p=0;
    vis[0]=1;
    for(int i=0;i<t;i++){
        for(int j=0;j<=b[i]*a[i];j+=a[i]){
            for(int k=0;k<=p;k++){
                if(k+j>sum/2){
                    break;//是break不是return不然会少添加数。。
                }
                if(vis[k]==1){
                    vis[k+j]=1;
                }
            }
        }
        p+=a[i]*b[i];
    }
}
int main()
{
    while(scanf("%d",&t)!=EOF){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        if(t==-1){
            break;
        }
        sum=0;
        for(int i=0;i<t;i++){
            scanf("%d%d",&a[i],&b[i]);
            sum+=a[i]*b[i];
        }
        func();
        for(int i=sum/2;i>=0;i--){
            if(vis[i]==1){
                ans=i;
                break;
            }
        }
        printf("%d %d\n",sum-ans,ans);
    }
}

