#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int tmp=n;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                while(n%i==0){
                    n/=i;
                }
                tmp=(tmp/i)*(i-1);
            }
            if(n<i+1){
                break;
            }
        }
        if(n>1){
            tmp=(tmp/n)*(n-1);
        }
        printf("%d\n",tmp);
    }
}
