#include <cstdio>
#include <algorithm>
#define N 110
using namespace std;
struct node{
    int u,v;
    int w;
}edge[N*N];
int par[N];
bool cmp(node a,node b){
    return a.w<b.w;
}
void init(int n){
    int i;
    for(i=1;i<=n;i++){
        par[i]=i;
    }
}
int findpar(int x){
    //int a;
    if(x==par[x]){
        return x;
    }
    else{
        return findpar(par[x]);
    }
}
int kruscal(int n,int m){
	int num=1;
	int i,x,y,sum=0;
	init(n);
    for(i=1;i<=n;i++){
        x=edge[i].u;
        y=edge[i].v;
        x=findpar(x);
        y=findpar(y);
        if(x!=y){
        	num++;
            sum+=edge[i].w;
            par[y]=x;
        }
    }
    if(num==m){
        //printf("%d\n",sum);
    	return sum;
    }
    else{
    	return -1;
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m,i,a,b,c,ans;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0){
            break;
        }
        for(i=1;i<=n;i++){
            scanf("%d%d%d",&a,&b,&c);
            edge[i].u=a;
            edge[i].v=b;
            edge[i].w=c;
        }
        sort(edge+1,edge+1+n,cmp);
        ans=kruscal(n,m);
        if(ans==-1){
        	printf("?\n");
        }
        else{
        	printf("%d\n",ans);
        }
    }
    return 0;
}
