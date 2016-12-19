#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long p[100];
int main()
{
    int m;
    memset(p,0,sizeof(p));
    for(int i=0;i<=63;i++){
        for(int j=0;j<=63;j++){
            p[i&j]++;
            m=max(m,i&j);
        }
    }
    int b;
    long long ans;
    string a;
    while(cin>>a){
        ans=1;
        for(int i=0;i<a.size();i++){
            if(a[i]>='0'&&a[i]<='9'){
                b=a[i]-'0';
            }
            else if(a[i]>='A'&&a[i]<='Z'){
                b=a[i]-'A'+10;
            }
            else if(a[i]>='a'&&a[i]<='z'){
                b=a[i]-'a'+36;
            }
            else if(a[i]=='-'){
                b=a[i]-'-'+62;
            }
            else if(a[i]=='_'){
                b=a[i]-'_'+63;
            }
            ans=(ans*(p[b]%mod))%mod;
        }
        cout<<ans<<endl;
    }

}
