#include "cstdio"
struct node{
	int l,r;
	int flag;
	int num;
	int lenth;
}seq[N];
void build(int i,int l,int r){
	seq[i].r=r;
	seq[i].l=l;
	seq[i].num=seq[i].flag=seq[i].lenth=0;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
}
void update(int i,)
int main()
{
	
}