#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,now;
    long long num;
    while(scanf("%d%d",&a,&b)!=EOF){
        num=0;
        while(a>0&&b>0){
            if(a==1&&b==1){
                break;
            }
            num++;
            if(a<b){
                if(a+1<100)
                a++;
                b-=2;
            }
            else{
                if(b+1<100)
                b++;
                a-=2;
            }
        }
        printf("%I64d\n",num);
    }
    return 0;
}
