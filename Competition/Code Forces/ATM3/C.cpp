#include <bits/stdc++.h>
#define MAX 500008
#define ll long long
using namespace std;
string a;
int main()
{
    while(cin>>a){
        int p=-1;
        if(a[0]=='a'){
            for(int i=0;i<a.size();i++){
                if(a[i]!='a'&&p==-1){
                    a[i]=a[i]-1;
                    p=1;
                }
                else if(a[i]!='a'&&p==1){
                     a[i]=a[i]-1;
                }
                else if(a[i]=='a'&&p!=-1){
                    break;
                }
            }
        }
        else{
            for(int i=0;i<a.size();i++){
                if(a[i]=='a'){
                    break;
                }
                p=1;
                a[i]=a[i]-1;
            }
        }
        if(p==-1){
            a[a.size()-1]='z';
        }
        cout<<a<<endl;
    }
}
