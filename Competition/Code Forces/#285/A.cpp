#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,e,f;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
        e=max((3*a)/10,(a-(a/250*c)));
        f=max((3*b)/10,(b-(b/250*d)));
        //cout<<e<<f;
        if(e>f){
            printf("Misha\n");
        }
        else if(e<f){
            printf("Vasya\n");
        }
        else{
            printf("Tie\n");
        }
    }
    return 0;
}
