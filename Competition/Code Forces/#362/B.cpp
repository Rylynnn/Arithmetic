#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    string b,c;
    int num,p,ans,now,nnum,pp;
    while(cin>>a){
        b.clear();
        c.clear();
        num=0;
        nnum=2;
        p=0;
        pp=0;//cout<<a.size()<<endl;
        for(int i=0;i<a.size();i++){
            if(a[i]=='e'){
                p=1;
                continue;
            }
            if(p==0){
                b.push_back(a[i]);
            }
            else if(p==1){
                c.push_back(a[i]);
            }
        }
        ans=0;
        int t=1;
        num=c.size();
        nnum=b.size();
        for(int i=num-1;i>=0;i--){
            ans+=(c[i]-'0')*t;
            t*=10;
        }
        if(ans<nnum-2){
            if(nnum==3&&b[2]=='0'){
                cout<<b[0]<<endl;
                continue;
            }
            cout<<b[0];
            for(int i=0;i<ans;i++){
                cout<<b[2+i];
            }
            cout<<'.';
            for(int i=ans+2;i<nnum;i++){
                cout<<b[i];
            }
            cout<<'\n';
        }
        else{
            for(int i=0;i<nnum;i++){
                if(b[i]!='.')
                cout<<b[i];
            }
            for(int i=nnum-2;i<ans;i++){
                cout<<'0';
            }
            cout<<'\n';
        }
    }
    return 0;
}
