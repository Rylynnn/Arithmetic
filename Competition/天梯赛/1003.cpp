#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string a;
    int p[10];
    while(cin>>a){
        memset(p,0,sizeof(p));
        for(int i=0;i<a.size();i++){
            p[a[i]-'0']++;
        }
        for(int i=0;i<10;i++){
            if(p[i]!=0){
                cout<<i<<':'<<p[i]<<endl;
            }
        }
    }
    return 0;
}
