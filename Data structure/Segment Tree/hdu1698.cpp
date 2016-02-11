#include <cstdio>
#define N 100010
struct node{
	int l,r;
	int sum;
	int lazy,num;
}seq[3*N];
void build(int i,int l,int r){
	seq[i].l=l;
	seq[i].r=r;
	seq[i].lazy=0;
	if(l==r){
		seq[i].sum=1;
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	seq[i].sum=seq[i<<1].sum+seq[i<<1|1].sum;
}
void pd(int i){
	if(seq[i].lazy){
		seq[i<<1].sum=(seq[i<<1].r-seq[i<<1].l+1)*seq[i].lazy;
		seq[i<<1|1].sum=(seq[i<<1|1].r-seq[i<<1|1].l+1)*seq[i].lazy;
		seq[i<<1].lazy=seq[i<<1|1].lazy=seq[i].lazy;
		seq[i].lazy=0;
	}
}
void update(int i,int l,int r,int v){
	if(seq[i].l==l&&seq[i].r==r){
		seq[i].lazy=v;
		seq[i].sum=(r-l+1)*v;
		return;
	}
	pd(i);
	int mid=(seq[i].l+seq[i].r)>>1;
	if(r<=mid)update(i<<1,l,r,v);
    else if(l>mid)update((i<<1)|1,l,r,v);
    else
    {
        update(i<<1,l,mid,v);
        update((i<<1)|1,mid+1,r,v);
    }
    seq[i].sum=seq[i<<1].sum+seq[(i<<1)|1].sum;
        //printf("%d %d:%d\n",seq[i<<1].l,seq[i<<1].r,seq[i<<1].sum);    printf("%d %d:%d\n",seq[i<<1|1].l,seq[i<<1|1].r,seq[i<<1|1].sum);
    //printf("%d %d:%d\n",seq[i].l,seq[i].r,seq[i].sum);
}
int main()
{
	int x,y,z,i;
	int n,q,t;
	scanf("%d",&t);
	for(int j=1;j<=t;j++){
		scanf("%d%d",&n,&q);
		build(1,1,n);
		for(i=1;i<=q;i++){
			scanf("%d%d%d",&x,&y,&z);
			update(1,x,y,z);
		}
		printf("Case %d: The total value of the hook is %d.\n",j, seq[1].sum);
	}
	return 0;
}
