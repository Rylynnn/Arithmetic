#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,n1,n0;
    string a;
    scanf("%d",&n);
    cin>>a;
    n1=n0=0;
    for(int i=0;i<n;i++){
        if(a[i]=='0'){
            n0++;
        }
        else if(a[i]=='1'){
            n1++;
        }
    }
    printf("%d\n",n-min(n1,n0)*2);
    return 0;
}
