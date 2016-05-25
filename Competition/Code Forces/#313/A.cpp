/*输出不能表示的最小的数。。。。那不就是1么。。。。。。这哪个逗逼出的题。。。*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    int i,p=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a);
        if(a==1){
            p=1;
            printf("-1\n");
        }
    }
    if(p==0){
        printf("1\n");
    }
    return 0;
}
