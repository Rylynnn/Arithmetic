#include <cstdio>
struct node{
    int l,r;
    int num;
}tree[100];
void init(){
    for(int i=0;i<n;i++){
        tree[i].l=tree[i].r=0;
    }
}
void build(int i,int x){
    if(i==n){
        return;
    }
    for(int j=1;j<=n;j++){
        if(b[j]==a[x]){
            build(i+1,x)
        }
    }
}
int main()
{
    int n;
    int a[50],b[50];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    tree[1].num=a[n];
    init();
    build(1,);
}
