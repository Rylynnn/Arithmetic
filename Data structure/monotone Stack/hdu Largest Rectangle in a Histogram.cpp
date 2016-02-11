#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long long p[100010]={-1},l[100010];//单调找
    long long r,h,ans;
    int t,i;
    while(scanf("%d",&t)!=EOF&&t!=0){
        ans=0;
        int top=0;
        for(i=1;i<=t+1;i++){
            if(i==t+1){
                h=0;
            }//要进行把最后的栈中所有元素放出的工作
            else{
                scanf("%lld",&h);
            }
            if(h>p[top]){
                p[++top]=h;
                l[top]=1;
            }
            else{
                r=0;
                while(h<=p[top]){
                    ans=max(ans,(r+l[top])*p[top]);
                    r+=l[top--];
                }//每次更新单调栈中的顶值为最右边时，向左延伸所能达到的最大的矩形面积，并出栈
                p[++top]=h;//重新更新栈顶
                l[top]=r+1;//每次全部出栈之后的新栈底的左宽
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
