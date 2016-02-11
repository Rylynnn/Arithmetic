#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
bool cmp(int c,int d){
    return c<d;
}
int main()
{
    int n,i,b,time;
    int a[15];
    while(scanf("%d",&n)!=EOF){
        time =0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n,cmp);
        i=1;
        a[0]=0;
        while(i<=n){
            time+=(a[i]-a[i-1])*6+5;
            //printf("%d ",time);
            i++;
            while(a[i]==a[i-1]&&i<=n){
                i++;
                //printf("%d ",i);
            }
        }
        time+=a[n]*4;
        printf("%d\n",time);
    }

}
