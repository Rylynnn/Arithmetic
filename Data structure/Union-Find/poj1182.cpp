/*1.设置关系
2.查询是否符合错误条件
3.合并建立新关系*/
#include<cstdio>
#define MAX 150010
int par[MAX];
int ran[MAX];
int init(int n){
    for(int i=1;i<=n;i++){
        par[i]=i;
        ran[i]=1;
    }
}
int findpar(int n){
    if(par[n]==n)
        return par[n];
    else return par[n]=findpar(par[n]);
}
void unit(int x,int y){
    x=findpar(x);
    y=findpar(y);
    if(x==y)return;
    if(ran[x]<ran[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(ran[x]==ran[y])ran[x]++;
    }
}
bool same(int x,int y){
    if(findpar(x)==findpar(y))return true;
    else return false;
}
int main(){
    int n,k;
    int x,y,t;
    scanf("%d%d",&n,&k);
    init(3*n);
    int wrong=0;
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&t,&x,&y);
        if(x<0||x>n||y<0||y>n){
            wrong++;
            continue;
        }
        if(t==2&&x==y){
            wrong++;
            continue;
        }
        if(t==1){
            if(same(x,y+n)||same(x,y+2*n)){
                wrong++;
            }
            else{
                unit(x,y);
                unit(x+n,y+n);
                unit(x+2*n,y+2*n);
            }
        }
        if(t==2){
            if(same(x,y)||same(x,y+2*n)){
                wrong++;
            }
            else{
                unit(x,y+n);
                unit(x+n,y+2*n);
                unit(x+2*n,y);
            }
        }
    }
    printf("%d",wrong);
    return 0;
}
