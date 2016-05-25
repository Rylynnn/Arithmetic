#include <cstdio>
#include <set>
using namespace std;
struct node{
    int num;
    int minm;
    int peo;
    int area;
    int home;
}par[5010];
int ran[5010];
void init(){
    int i;
    for(i=1;i<=10000;i++){
        par[i].num=par[i].minm=i;
        par[i].peo=1;
        par[i].area=par[i].home=0;
        ran[i]=1;
    }
}
int findpar(int x){
    if(par[x].num==x){
        return par[x].num;
    }
    else return par[x].num=findpar(par[x].num);
}
void unit(int x,int y){
    int xx=x,yy=y;
    x=findpar(x);
    y=findpar(y);
    if(x==y)return ;
    if(ran[x]<ran[y]){
        par[x].num=y;
        par[y].minm=min(par[y].minm,xx);
        par[y].peo+=1;
    }
    else{
        par[y].num=x;
        par[x].minm=min(par[x].minm,yy);
        par[x].peo+=1;
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
    int n,a,b,c,d,e,f,nn;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        unit(b,c);
        unit(a,b);
        scanf("%d",&nn);
        for(int j=0;j<nn;j++){
            scanf("%d",&d);
            unit(a,d);
        }
        scanf("%d%d",&e,&f);
        par[par[a].num].home+=e;
        par[par[a].num].area+=f;
    }

    return 0;
}
