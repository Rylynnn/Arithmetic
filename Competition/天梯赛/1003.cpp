#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <iostream>
using namespace std;
map <char,int> h;
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(int i=0;i<b.size();i++){
        h[b[i]]=1;
    }
    for(int i=0;i<a.size();i++){
        if(h[a[i]]!=1){
           printf("%c",a[i]);
        }
    }
    return 0;
}
