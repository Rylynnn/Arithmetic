#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string a;
    int p[4],maxm;
    while(cin>>a){
        memset(p,0,sizeof(p));
        maxm=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='G'||a[i]=='g'){
                p[0]++;
            }
            if(a[i]=='P'||a[i]=='p'){
                p[1]++;
            }
            if(a[i]=='L'||a[i]=='l'){
                p[2]++;
            }
            if(a[i]=='T'||a[i]=='t'){
                p[3]++;
            }
        }
        maxm=max(max(max(p[0],p[1]),p[2]),p[3]);
        for(int i=0;i<maxm;i++){
            if(p[0]!=0){
                p[0]--;
                cout<<'G';
            }
            if(p[1]!=0){
                p[1]--;
                cout<<'P';
            }
            if(p[2]!=0){
                p[2]--;
                cout<<'L';
            }
            if(p[3]!=0){
                p[3]--;
                cout<<'T';
            }
        }
        cout<<endl;
    }
    return 0;
}
