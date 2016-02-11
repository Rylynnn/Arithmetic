/*
wrong1:位运算中i<<1+1==i<<2!!!!若变为i*2+1应为(i<<1)+1
*/
#include <cstdio>
#include <algorithm>
#define N 5010
using namespace std;
struct node{
	int l,r;
	int num;
}seq[N];
void build(int i,int l,int r){
	seq[i].l=l;
	seq[i].r=r;
	seq[i].num=0;
	//printf("%d:%d %d:%d\n",i,seq[i].l,seq[i].r,seq[i].num);
	if(l==r){
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
}
void update(int i,int p){
	if(seq[i].l==seq[i].r){
		seq[i].num++;
		return;
	}
	int mid=(seq[i].l+seq[i].r)>>1;
	if(p<=mid){
		update(i<<1,p);
	}
	else if(p>mid){
		update(i<<1|1,p);
	}
	seq[i].num=seq[i*2].num+seq[i*2+1].num;
}
int quary(int i,int b,int e){
	if(seq[i].l==b&&seq[i].r==e){
		return seq[i].num;
	}
	int mid=(seq[i].l+seq[i].r)/2;
	//printf("%d ",mid);
	if(e<=mid){
		return quary(i<<1,b,e);
	}
	else if(b>mid){
		return quary(i<<1|1,b,e);
	}
	else{
		return quary(i<<1,b,mid)+quary(i<<1|1,mid+1,e);
	}
}
int main()
{
	int n;
	int i;
	int a[N];
	while(scanf("%d",&n)!=EOF){
		build(1,0,n-1);
     //printf("%d",n);
		int sum=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=quary(1,a[i],n-1);
			//printf("%d ",quary(1,a[i],n-1));
			update(1,a[i]);
		}
		/*for(i=1;i<2*n;i++){
            printf("%d:%d %d:%d\n",i,seq[i].l,seq[i].r,seq[i].num);
		}*/
		int ans=sum;
		for(i=1;i<=n;i++){
			sum-=a[i]-n+1+a[i];
			ans=min(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
