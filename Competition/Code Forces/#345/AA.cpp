#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,now;
    long long num;
    while(scanf("%d%d",&a,&b)!=EOF){
        num=0;
        if(a<b){
            now=-1;
        }
        else{
            now=-2;
        }
        while(a!=0&&b!=0){
            if(a==1&&b==1){
                break;
            }
            num++;
            if(now==-1){
                b-=2;
                a++;
                if(b==1||b==2){
                    now=-2;
                    continue;
                }
                else{
                    continue;
                }
            }
            else if(now==-2){
                a-=2;
                b++;
                if(a==1||a==2){
                    now=-1;
                    continue;
                }
                else{
                    continue;
                }
            }
        }
        printf("%I64d\n",num);
    }
    return 0;
}
