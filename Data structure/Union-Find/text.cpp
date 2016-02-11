#include <cstdio>
#define N 1000000
struct node
{
	int l,r;
	int sum,lazy;
}seq[N];
void pushup(int i){
	seq[i].sum=seq[i<<1].sum+seq[i<<1|1].sum;
}
void build(int i,int l,int r){
	seq[i].r=r;
	seq[i].l=l;
	while(r==l){
		seq[i].sum=a[i];
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	pushup(i);
}
void pushdown(int i){
	seq[i<<1].lazy+=seq[i].lazy;
	seq[i<<1].sum+=(seq[i<<1].l-seq[i<<1].r+1)*seq[i].lazy;
	seq[i<<1|1].lazy+=seq[i].lazy;
	seq[i<<1|1].sum+=(seq[i<<1|1].l-seq[i<<1|1].r+1)*seq[i].lazy;
	seq[i].lazy=0;
}
void update(int i,int l,int r,int k){
	if(l<=seq[i].l&&seq[i].r>=r){
		seq[i].sum+=(seq[i].r-seq[i].l+1)*k;
		seq[i].lazy+=k;
		return;
	}
	pushdown(i);
	int mid=(seq[i].r+seq[i].l)>>1;
	if(l<mid){
		update(i<<1,l,r,k);
	}
	else if(r>mid){
		update(i<<1|1,l,r,k);
	}
	pushup(i);
}
int quary(int i,int l,int r){
	if(l==seq[i].l&&seq[i].r==r){
		return seq[i].sum;
	}
	pushdown(i);
	int mid=(seq[i].r+seq[i].l)>>1;
	if(r<mid){
		return sum+=quary(i<<1,l,mid);
	}
	else if(l>mid){
		return sum+=quary(i<<1|1,mid+1,r);
	}
	else{
		return sum+=quary(i<<1,l,mid)+quary(i<<1|1,mid+1,r);
	}
}
int main(){	
	int i;
	while(scanf("%d",&n)!=EOF){

	}
}