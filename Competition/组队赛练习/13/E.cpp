#include <bits/stdc++.h>
#define eps 1e-6
#define MAX 20000001
#define ll long long
using namespace std;
ll f[MAX+6],s[MAX+6],n;
int main()
{
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    for(int i=2;i<=MAX;i++){
        f[i]=1+i;
    }
    for(int i=2;i<=MAX;i++){
        for(int j=i<<1;j<=MAX;j+=i){
            f[j]+=i;
        }
    }
    s[2]=3;
    for(int i=3;i<=MAX;i++){
        s[i]=s[i-1]+f[i];
    }
    while(scanf("%lld",&n)!=EOF){
        if(n==0){
            break;
        }
        printf("%lld\n",s[n]);
    }
    return 0;
}
