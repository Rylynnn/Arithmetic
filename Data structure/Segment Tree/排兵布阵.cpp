#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
struct a{
    int rchild;
    int lchild;
    int value;
}arm[100000000];
int v[50010];
int ex;
void build(int n,int b,int e);
void push(int n);
void update(int n,int i,int j);
int query(int n,int i,int j);
int main()
{
    int t,a,b,i,j;
    string s;
    scanf("%d",&t);
    for(j=1;j<=t;j++){
        scanf("%d",&ex);
        for(i=1;i<=ex;i++){
            scanf("%d",&v[i]);
        }
        build(1,1,ex);
        printf("Case %d:\n",j);
        while(cin>>s&&s!="End"){
            scanf("%d%d",&a,&b);
            if(s=="Add"){
                v[a]+=b;
                update(1,a,b);
            }
            if(s=="Sub"){
                v[a]-=b;
                update(1,a,b);
            }
            if(s=="Query")printf("%d\n",query(1,a,b));
        }
    }
    return 0;
}
void build(int n,int b,int e){
    if(e==b){
        arm[n].rchild=arm[n].lchild=b;
        arm[n].value=v[b];
        return;
    }
    build(n*2,b,(b+e)/2);
    build(n*2+1,(b+e)/2+1,e);
    push(n);
}
void push(int n){
    arm[n].value=arm[n*2].value+arm[n*2+1].value;
    arm[n].lchild=arm[n*2].lchild;
    arm[n].rchild=arm[n*2+1].rchild;
}
int query(int n,int i,int j){
    if(arm[n].lchild==i&&arm[n].rchild==j)return arm[n].value;
    int mid=(arm[n].rchild+arm[n].lchild)/2;
    if(j<=mid)return query(n*2,i,j);
    if(i>mid)return query(n*2+1,i,j);
    return query(2*n,i,mid)+query(2*n+1,mid+1,j);
}
void update(int n,int i,int j){
    if(arm[n].lchild==arm[n].rchild){
        arm[n].value=v[arm[n].lchild];
        return;
    }
    int mid=(arm[n].lchild+arm[n].rchild)/2;
    if(i<=mid)update(2*n,i,j);
    if(i>mid)update(2*n+1,i,j);
    push(n);
}

