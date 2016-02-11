#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct s{
    int r,l;
    int m;
}student[10000000];
int mark[10000000];
void build(int n,int b,int e);
void update(int n,int i,int j);
int query(int n,int i,int j);
void push(int n);
int main()
{
    int n,m,i,a,b;
    string obey;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&mark[i]);
        }
        build(1,1,n);
        //for(i=1;i<=10;i++)
            //printf("%d=%d:%d",student[i].l,student[i].r,student[i].m);
        for(i=1;i<=m;i++){
            cin>>obey;
            scanf("%d%d",&a,&b);
            if(obey=="Q"){
                printf("%d\n",query(1,a,b));
            }
            if(obey=="U"){
                update(1,a,b);
            }
        }
    }
    return 0;
}
void build(int n,int b,int e){
    if(b==e){
        student[n].l=student[n].r=b;
        student[n].m=mark[b];
        return;
    }
    build(2*n,b,(b+e)/2);
    build(2*n+1,(b+e)/2+1,e);
    push(n);
}
int query(int n,int i,int j){
    if(student[n].l==i&&student[n].r==j)return student[n].m;
    int mid=(student[n].r+student[n].l)/2;
    if(j<=mid)return query(2*n,i,j);
    if(i>mid)return query(2*n+1,i,j);
    return max(query(2*n,i,mid),query(2*n+1,mid+1,j));
}
void push(int n){
    student[n].m=max(student[2*n].m,student[2*n+1].m);
    student[n].l=student[2*n].l;
    student[n].r=student[2*n+1].r;
}
void update(int n,int i,int j){
    if(student[n].r==student[n].l){
        student[n].m=j;
        return;
    }
    int mid=(student[n].r+student[n].l)/2;
    if(i<=mid)update(2*n,i,j);
    if(i>mid)update(2*n+1,i,j);
    push(n);
}
