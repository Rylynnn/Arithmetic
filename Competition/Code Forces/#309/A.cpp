#include <bits/stdc++.h>
using namespace std;
map <string,int> h;
int main()
{
    int ans,i,j,k,p;
    string a,b,now;
    while(cin>>a){
        ans=0;
        for(i=0;i<=a.size();i++){
            for(j=0;j<26;j++){
                b=a;
                now=j+'a';
                if(i==0){
                    b=now+b;
                }
                else if(i==a.size()){
                    b=b+now;
                }
                else{
                    b.insert(i,now);
                }
                if(!h[b]){
                    ans++;
                    h[b]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
