#include <bits/stdc++.h>
#define MAX 500008
#define ll long long
using namespace std;
ll a,n,x[100007],b1,b2,c1,c2;
int main()
{
    while(cin>>n>>a){
        for(int i=0;i<n;i++){
            scanf("%I64d",&x[i]);
        }
        sort(x,x+n);
        if(n==1){
            printf("0\n");
            continue;
        }
        ans=0x3f3f3f3f;
        ans=min(ans,abs(a-x[0])+abs(x[n-2]-x[0]));
        ans=min(ans,abs(a-x[1])+abs(x[n-1]-x[1]));
        ans=min(ans,abs(a-x[n-1])+abs(x[n-1]-x[1]));
        ans=min(anms,abs(a-x[n-2])+abs(x[n-2]-x[0]));
        printf("%I64d\n",min(min(b1,min(b2,c1)),c2));

    }
}
