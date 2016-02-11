/*
线段树复习。。没想到忘这么多。。而且还出现了赋值多打一个等号变成判等的情况。。好可怕。。TAT
*/
#include <cstdio>
#include <algorithm>
#define N 50010
using namespace std;
struct node{
	int l;
	int r;
	int b,s;
}seq[3*N];
int a[N];
void pu(int n){
	seq[n].b=max(seq[n<<1].b,seq[(n<<1)|1].b);
	seq[n].s=min(seq[n<<1].s,seq[(n<<1)|1].s);
}
void build(int n,int l,int r){
	seq[n].l=l;
	seq[n].r=r;
	/*for(int i=1;i<=20;i++)
            printf("%d=%d:%d %d\n",seq[i].l,seq[i].r,seq[i].b,seq[i].s);
    */
	if(l==r){
		seq[n].b=seq[n].s=a[l];
		return;//注意return！
	}
	int mid=(l+r)>>1;
	build(n<<1,l,mid);
	build((n<<1)|1,mid+1,r);
	pu(n);
}
int getbig(int n,int l,int r){
	if(seq[n].l==l&&seq[n].r==r){
		return seq[n].b;
	}
	int mid=(seq[n].l+seq[n].r)>>1;
	if(r<=mid){
		return getbig(n<<1,l,r);
	}
	else if(mid<l){
		return getbig((n<<1)|1,l,r);
	}
	else{
        return max(getbig(n<<1,l,mid),getbig((n<<1)|1,mid+1,r));
	}
}
int getsmall(int n,int l,int r){
	if(seq[n].l==l&&seq[n].r==r){
		return seq[n].s;
	}
	int mid=(seq[n].l+seq[n].r)>>1;//这里是当前节点的中间值
	if(r<=mid){
		return getsmall(n<<1,l,r);
	}
	else if(mid<l){
		return getsmall((n<<1)|1,l,r);
	}
	else{
        return min(getsmall(n<<1,l,mid),getsmall((n<<1)|1,mid+1,r));//不符合条件分裂当前线段
	}
}
int main(){
    int n,q,i,b,c;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    }
    build(1,1,n);
    for(i=1;i<=q;i++){
    	scanf("%d%d",&b,&c);
    	printf("%d\n",getbig(1,b,c)-getsmall(1,b,c));
    }
}
