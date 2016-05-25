#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    while(scanf("%d%d",&n,&x)!=EOF){
        long long num=0;
        for(int i=1;i<=n;i++){
            if(x%i==0&&(x/i)<=n&&(x/i)>=1){
                num++;
            }
        }
        printf("%I64d\n",num);
    }
    return 0;
}
