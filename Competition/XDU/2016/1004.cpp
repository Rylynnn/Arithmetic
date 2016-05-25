#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int x,y,a,now;
    while(scanf("%d%d%d",&x,&y,&a)!=EOF){
        now=a%(x+y);
        if(now>0&&now<=x){
            printf("wanshen\n");
        }
        else if(now==0||now>x&&now<x+y){
            printf("light\n");
        }
    }
    return 0;
}
