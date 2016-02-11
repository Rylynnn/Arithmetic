/*
要找到比x大的第k个数，先求出比x小的数的个数s，然后求原序列的第k+s小的数
*/
#include <cstdio>
#include <cstring>
#define lowbit(x) x&(-x)
#define N 100010
int bit[N];
void update(int x,int a){
    //printf("%d %d %d\n",x,a,N);
	while(x<N){
        //printf("3\n");
		bit[x]+=a;
		//printf("%d",bit[x]);
		x+=lowbit(x);
	}
}
int getsum(int x){
	int sum=0;
	while(x>0){
		sum+=bit[x];
		x-=lowbit(x);
	}
	return sum;
}
int binarys(int x){
    int l=0,r=N,mid;
    while(l<r-1){
        mid=(r+l)>>1;
        if(getsum(mid)>=x){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return r;
}
int main()
{
	int n,i,a,b,p,s;
	while(scanf("%d",&n)!=EOF){
        memset(bit,0,sizeof(bit));
		for(i=1;i<=n;i++){
			scanf("%d%d",&p,&a);
			if(p==0){
                //printf("%d",a);
				update(a,1);

			}
			else if(p==1){
				if(getsum(a)-getsum(a-1)==0){//刚开始采用binary——sreach查找,后使用前后求和的差若为0（这个数值本身没有被更新），则该数被没有被添加过
                    printf("No Elment!\n");
				}
				else{
                    update(a,-1);
				}
			}
			else{
                scanf("%d",&b);
                s=getsum(a);
                if(s+b<=getsum(N)){
                    printf("%d\n",binarys(s+b));
                }
                else{
                    printf("Not Find!\n");
                }
			}
		}
	}
    return 0;
}
