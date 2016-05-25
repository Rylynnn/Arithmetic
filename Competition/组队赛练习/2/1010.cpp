#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v1,v2,r,d,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&v1,&v2,&r,&d);
        printf("%s\n",(1.0*v2*r/v1)*asin(1.0*v1*r/(r*v2))<d?"Wake up to code":"Why give up treatment");
    }
    return 0;
}
