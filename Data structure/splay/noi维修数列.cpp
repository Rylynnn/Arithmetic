#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf 1000000000
#define N 1000005
using namespace std;
int n,m,rt,cnt;
int a[N],id[N],fa[N],c[N][2];
int sum[N],siz[N],v[N],mx[N],lx[N],rx[N];
bool tag[N],rev[N];
queue<int> q;
void update(int x){//和线段树pushup一个意思
	int l=c[x][0],r=c[x][1];
	sum[x]=sum[l]+sum[r]+v[x];
	siz[x]=siz[l]+siz[r]+1;
	mx[x]=max(mx[l],mx[r]);
	mx[x]=max(mx[x],rx[l]+v[x]+lx[r]);
	lx[x]=max(lx[l],sum[l]+v[x]+lx[r]);
	rx[x]=max(rx[r],sum[r]+v[x]+rx[l]);
}
void pushdown(int x){//和线段树pushdown一个意思
	int l=c[x][0],r=c[x][1];
	if(tag[x]){
		rev[x]=tag[x]=0;
		if(l)tag[l]=1,v[l]=v[x],sum[l]=v[x]*siz[l];
		if(r)tag[r]=1,v[r]=v[x],sum[r]=v[x]*siz[r];
		if(v[x]>=0){
			if(l)lx[l]=rx[l]=mx[l]=sum[l];
			if(r)lx[r]=rx[r]=mx[r]=sum[r];
		}
		else {
			if(l)lx[l]=rx[l]=0,mx[l]=v[x];
			if(r)lx[r]=rx[r]=0,mx[r]=v[x];
		}
	}
	if(rev[x]){
		rev[x]^=1;
		rev[l]^=1;
		rev[r]^=1;
		swap(lx[l],rx[l]);
		swap(lx[r],rx[r]);
		swap(c[l][0],c[l][1]);
		swap(c[r][0],c[r][1]);
	}
}
void rot(int x,int &k){//x往接近k的方向旋转
	int y=fa[x],z=fa[y],l,r;
	l=(c[y][1]==x);
	r=l^1;
	if(y==k){
        k=x;
	}
	else{
        c[z][c[z][1]==y]=x;
	}
	fa[c[x][r]]=y;
	fa[y]=x;
	fa[x]=z;
	c[y][l]=c[x][r];
	c[x][r]=y;
	update(y);
	update(x);
}
void splay(int x,int &k){//把x旋转到k的位置
	while(x!=k){
		int y=fa[x],z=fa[y];
	    if(y!=k){
			if(c[y][0]==x^c[z][0]==y){
                rot(x,k);
			}
			else{
                rot(y,k);
			}
		}
		rot(x,k);
	}
}
int find_r(int x,int rk){//寻找x往右第rk个元素
	pushdown(x);
	int l=c[x][0],r=c[x][1];
	if(siz[l]+1==rk){
        return x;
	}
	if(siz[l]>=rk){
        return find_r(l,rk);
	}
	else{
	    return find_r(r,rk-siz[l]-1);
	}
}
void rec(int x){//删除节点X和其子树
	if(!x)return;
	int l=c[x][0],r=c[x][1];
	rec(l);
	rec(r);
	q.push(x);
	fa[x]=c[x][0]=c[x][1]=0;
	tag[x]=rev[x]=0;
}
int split(int k,int tot){//把从k开始的tot个转移到以k为根的子树中
	int x=find_r(rt,k),y=find_r(rt,k+tot+1);
	splay(x,rt);
	splay(y,c[x][1]);
	return c[y][0];
}
void query(int k,int tot){//输出从k开始连续tot个之和
	int x=split(k,tot);
	printf("%d\n",sum[x]);
}
void modify(int k,int tot,int val){//从K开始连续tot个改为val
	int x=split(k,tot),y=fa[x];
	v[x]=val;
	tag[x]=1;
	sum[x]=siz[x]*val;
	if(val>=0){
        lx[x]=rx[x]=mx[x]=sum[x];
	}
	else{
        lx[x]=rx[x]=0,mx[x]=val;
	}
	update(y);
	update(fa[y]);
}
void rever(int k,int tot){//从k开始反转K个
	int x=split(k,tot),y=fa[x];
	if(!tag[x]){
		rev[x]^=1;
		swap(c[x][0],c[x][1]);
		swap(lx[x],rx[x]);
		update(y);
		update(fa[y]);
	}
}
void erase(int k,int tot){//从k开始擦除tot个
	int x=split(k,tot),y=fa[x];
	rec(x);
	c[y][0]=0;
	update(y);
	update(fa[y]);
}
void build(int l,int r,int f){//建立一棵splay，从l到r，根是f
	if(l>r)return;
	int mid=(l+r)>>1,now=id[mid],last=id[f];
	if(l==r){
		sum[now]=a[l];
		siz[now]=1;
		tag[now]=rev[now]=0;
		if(a[l]>=0){
            lx[now]=rx[now]=mx[now]=a[l];
		}
		else{
            lx[now]=rx[now]=0,mx[now]=a[l];
		}
	}
	else{
        build(l,mid-1,mid);
        build(mid+1,r,mid);
	}
	v[now]=a[mid];
	fa[now]=last;
	update(now);
	c[last][mid>=f]=now;
   }
void insert(int k,int tot){//在第k个元素后面插入tot个元素
	for(int i=1;i<=tot;i++){
        scanf("%d",&a[i]);
	}
	for(int i=1;i<=tot;i++){
		if(!q.empty()){
            id[i]=q.front(),q.pop();
		}
		else{
            id[i]=++cnt;
		}
    }
	build(1,tot,0);
	int z=id[(1+tot)>>1];
	int x=find_r(rt,k+1),y=find_r(rt,k+2);
	splay(x,rt);
	splay(y,c[x][1]);
	fa[z]=y;
	c[y][0]=z;
	update(y);
	update(x);
}
int main()
{
	scanf("%d%d",&n,&m);
	mx[0]=a[1]=a[n+2]=-inf;
	for(int i=1;i<=n;i++){
        scanf("%d",&a[i+1]);
	}
	for(int i=1;i<=n+2;i++){
        id[i]=i;
	}
	build(1,n+2,0);
	rt=(n+3)>>1;
	cnt=n+2;
	int k,tot,val;
	char ch[10];
	while(m--){
		scanf("%s",ch);
		if(ch[0]!='M'||ch[2]!='X'){
            scanf("%d%d",&k,&tot);
		}
		if(ch[0]=='I'){
            insert(k,tot);
		}
		if(ch[0]=='D'){
            erase(k,tot);
		}
		if(ch[0]=='M'){
			if(ch[2]=='X'){
                printf("%d\n",mx[rt]);
			}
			else{
                scanf("%d",&val);
                modify(k,tot,val);
			}
		}
		if(ch[0]=='R'){
            rever(k,tot);
		}
		if(ch[0]=='G'){
            query(k,tot);
		}
	}
	return 0;
}
