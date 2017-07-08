
/*
ID:15829681
LANG:C++
TASK:frac1
*/
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#define FRO
using namespace std;
int gcd(int a,int b){
    return (b==0)?a:gcd(b,a%b);
}
struct node{
    int nu,de;
    node(){};
    node(int a,int b){
        nu=a;
        de=b;
    };
}num[40009];
bool cmp(node a,node b){
    int ttmp=gcd(b.de,a.de);
    if(b.nu*(a.de/ttmp)-a.nu*(b.de/ttmp)>0){
        return true;
    }
    else{
        return false;
    }
}
int n;
int vis[207][207];
int main()
{
    #ifdef FRO
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    #endif // FRO
    scanf("%d",&n);
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
    int tmp=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            node now;
            now.nu=j/gcd(i,j);
            now.de=i/gcd(i,j);
            if(vis[now.nu][now.de]==0){
                vis[now.nu][now.de]=1;
                num[tmp++]=now;
            }
        }
    }
    sort(num,num+tmp,cmp);
    for(int i=0;i<tmp;i++){
        printf("%d/%d\n",num[i].nu,num[i].de);
    }
}
