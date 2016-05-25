#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#define MOD 9973
using namespace std;
struct s{
    int r,l;
    int m;
}student[10000007];
string a;
void build(int n,int b,int e);
void update(int n,int i,int j);
int query(int n,int i,int j);
void push(int n);
int c[100007],b[100007];
int main()
{
    cin.sync_with_stdio(false);
    int n,ans;
    while(cin>>n){
        cin>>a;
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        build(1,1,a.size());
        //for(int i=1;i<=50;i++)
        for(int i=0;i<n;i++){
            cin>>c[i]>>b[i];
            if(c[i]<1||c[i]>a.size()||b[i]<1||b[i]>a.size()){
                ans=query(1,c[i-1],b[i-1]);
            }
            else{
                ans=query(1,c[i],b[i]);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
void build(int n,int b,int e){
    if(b==e){
        student[n].l=student[n].r=b;
        student[n].m=(a[b-1]-28)%MOD;
        //printf("%d=%d:%d %d\n",student[n].l,student[n].r,student[n].m,a[b-1]);
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
    return (query(2*n,i,mid)%MOD)*(query(2*n+1,mid+1,j)%MOD)%MOD;
}
void push(int n){
    student[n].m=(student[2*n].m%MOD)*(student[2*n+1].m%MOD)%MOD;
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
