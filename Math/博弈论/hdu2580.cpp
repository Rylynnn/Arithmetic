#include<iostream>
#include<cstdio>
#include<cstring>
#include <cmath>
#define inf 10000000000LL
#define MAX 2000007
#define ll long long
using namespace std;
int a[MAX],b[MAX];
int main()
{
    int t,n,k,ans;
    while(scanf("%d",&t)!=EOF){
        int kase=0;
        while(t--){
            kase++;
            scanf("%d%d",&n,&k);
            b[0]=a[0]=1;
            int i=0,j=0;
            while(n>a[i]){
                i++;
                a[i]=b[i-1]+1;
                while(a[j+1]*k<a[i]){
                    j++;
                }
                if(a[j]*k<a[i]){
                    b[i]=b[j]+a[i];
                }
                else{
                    b[i]=a[i];
                }
            }
            printf("Case %d: ",kase);
            if(n==a[i]){
                printf("lose\n");
            }
            else{
                while(n>0){
                    if(n-a[i]>=0){
                        n-=a[i];
                        ans=a[i];
                    }
                    i--;
                }
                printf("%d\n",ans);
            }
        }

    }
    return 0;
}
