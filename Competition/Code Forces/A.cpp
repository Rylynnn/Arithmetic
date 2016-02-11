#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
    int a,i;
}p[110];
int cmp(node x,node y){
    return x.a<y.a;
}
int main()
{
    int n,k,num;
    while(scanf("%d %d",&n,&k)!=EOF){
        num=0;
        int i;
        for(i=0;i<n;i++){
            scanf("%d",&p[i].a);
            p[i].i=i+1;
        }
        sort(p,p+n,cmp);
        for(i=0;i<n;i++){
            if(k>=p[i].a){
                k-=p[i].a;
            }
            else{
                break;
            }
        }
        num=i;
        printf("%d\n",num) ;
        if(num==0)continue ;
        for(i=0;i<num-1;i++){
            printf("%d ",p[i].i);
        }
        printf("%d\n",p[i].i);
    }
    return 0;
}
