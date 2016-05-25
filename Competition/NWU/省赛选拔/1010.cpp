#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define eps 1e-9
using namespace std;
int main()
{
    int t,n;
    double a[107];
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&n);
            memset(a,0,sizeof(a));
            for(int i=0;i<n;i++){
                scanf("%lf",&a[i]);
            }
            sort(a,a+n);
            for(int i=0;i<n-1;i++){
                a[i+1]=(a[i+1]+a[i])/2;
                //cout<<a[i+1];
            }
            printf("%.2f\n",a[n-1]+eps);
        }
    }
    return 0;
}
