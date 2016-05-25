#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a[15],now,n;
    long long sum;
    for(int i=1;i<=10;i++){
        a[i]=1;
        now=i;
        while(now){
            a[i]*=now;
            now--;
        }
    }
    scanf("%d",&n);
    sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
    }
    cout<<sum<<endl;
}
