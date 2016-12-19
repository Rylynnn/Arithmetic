#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n,a[107],sum,maxm;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            sum=a[i];
            maxm=a[i];
            for(int k=i+1;k<i+j;k++){
                maxm=max(a[k],maxm);
                sum=sum^a[k];
            }
            printf("%d %d %d %d\n",i,j,sum,sum*maxm);
        }
    }
}
