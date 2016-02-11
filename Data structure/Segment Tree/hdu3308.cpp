#include <cstdio>
struct node{
	int l,r;
	int ll,rl;x
	int m;
}seg[N];
void pushup(int i){
	seg[i].l=seg[i<<1].l;
	seg[i].r=seg[i<<1|1].r;
	seg[i].m=max(seg[i<<1].m,seg[i<<1|1].m);
	if(seg[i<<1].rl<seg[i<<1|1].ll){

	}
}
void build(int i,int l,int r){
	if(l==r){
		seg[i].m=0;
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	pushup(i);
}
void update(int i,int a){
	if(seg[i].l==seg[i].r){
		
	}
}