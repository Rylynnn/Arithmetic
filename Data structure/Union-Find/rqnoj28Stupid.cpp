#include <cstdio>
#include <cstring>
using namespace std;
int n;
int par[1000010];
int a[1000010];
void unit(int x,int y);
void init(int n);
int fin(int x,int y);
int main()
{
    int i,a,b,niu,cai,ans;
    scanf("%d",&n);
    init(n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        unit(a,b);
        //printf("%d\n",par[b]);
    }
    scanf("%d%d",&niu,&cai);
    //printf("%d%d",niu,cai);
    ans=fin(niu,cai);
    printf("%d",ans);
}
void init(int n){
    int i;
    for(i=1;i<=n;i++){
        par[i]=i;
    }
}
void unit(int x,int y){
    par[y]=x;
}
int fin(int x,int y){
    memset(a,0,sizeof(a));
    //printf("%d",a[1]);
    int k=1,i,b;
    while(par[x]!=x){
        a[k++]=par[x];//标记x的所有祖先节点
        //printf("%d ",a[k-1]);
        x=par[x];
    }
    while(par[y]!=y){
        b=par[y];
        for(i=1;i<k;i++){
            if(b==a[i]){
                return b;
            }
        }
        y=par[y];
    }
}
