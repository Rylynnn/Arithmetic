#include <cstdio>
int par[N];
int rel[N];
void init(){
    for(i=1;i<=n;i++){
        par[i]=i;

    }
}
int getpar(int x){
    if(par[x]==x){
        return x;
    }
    else{
        return getpar(par[x]);
    }
}
int main()
{

}
