#include<cstdio>
int par[5010];
int ran[5010];
void init(int n){
    int i;
    for(i=1;i<=n;i++){
        par[i]=i;
        ran[i]=1;
    }
}
int findpar(int x){
    if(par[x]==x){
        return par[x];
    }
    else return par[x]=findpar(par[x]);
}
void unit(int x,int y){
    x=findpar(x);
    y=findpar(y);
    if(x==y)return ;
    if(ran[x]<ran[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(ran[x]==ran[y]){
        ran[x]++;
        }
    }
}
bool same(int x,int y){
    if(findpar(x)==findpar(y))return true;
    else return false;
}
int main()
{
    int n,m,p;
    int a,b;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++){
        init(n);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        unit(a,b);
    }
    for(int i=1;i<=p;i++){
        scanf("%d%d",&a,&b);
        if(same(a,b))printf("Yes\n");
        if(!same(a,b))printf("No\n");
    }
}
