/*
单点更新，每个seq[i]的根节点存h为i时能贴的海报长度
RE1：数组开小了（需要存N个根节点（满二叉树2*N-1是错的(在往大开到三倍)
*/
#include "cstdio"
#include "algorithm"
#define N 200010
using namespace std;
int height,weight,n,ans;
struct node{
	int l;
	int r;
	int lenth;
}seq[3*N];
void build(int i,int l,int r){
	seq[i].l=l;
	seq[i].r=r;
	seq[i].lenth=weight;
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
}
int update(int i,int a){//单点更新（每次用seq存第i行还剩多少内存（每个节点存当前线段内最大的可储存长度
	if(seq[i].l==seq[i].r){
		seq[i].lenth-=a;
		return seq[i].l;
	}
	if(seq[i<<1].lenth>=a){
		ans=update(i<<1,a);
	}
	else{
		ans=update(i<<1|1,a);
	}
	seq[i].lenth=max(seq[i<<1].lenth,seq[i<<1|1].lenth);
	return ans;
}
int main()
{
	int i,a;
	while(scanf("%d%d%d",&height,&weight,&n)!=EOF){
		if(height>n){
			height=n;
		}
		build(1,1,height);
		for(i=1;i<=n;i++){
			scanf("%d",&a);
			if(a>seq[1].lenth){
				printf("-1\n");
			}
			else{
				printf("%d\n",update(1,a));
			}
		}
	}
	return 0;
}
