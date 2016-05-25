#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){
        int i;
        i=fabs(((b+200*n)%n)+a);
        if(i%n!=0)
        printf("%d\n",i%n);
        else{
            printf("%d\n",i);
        }
    }
    return 0;
}
