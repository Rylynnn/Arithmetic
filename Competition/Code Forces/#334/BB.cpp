#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000007],maxm,ans;
int main()
{
    while(cin>>n>>k){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int num;
        num=n-k;
        maxm=a[n];
        for(int i=0;i<=num;i++){
            ans=a[i]+a[num-i+1];
            maxm=max(maxm,ans);
        }
        cout<<maxm<<endl;
    }
}
