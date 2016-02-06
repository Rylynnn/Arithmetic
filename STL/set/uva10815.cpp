#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;
set <string> dict;//排好序
int main()
{
    string s,buf;
    int i;
    while(cin>>s){
        for(i=0;i<s.length();i++){//将所有非字母的字符转变成空格，所有变成小写
            if(isalpha(s[i])){
                s[i]=tolower(s[i]);
            }
            else{
                s[i]=' ';
            }
            stringstream ss(s);//新的放入新的string
            while(ss>>buf){
                dict.insert(buf);
            }
         }
    }
    for(set<string>::iterator it=dict.begin();it!=dict.end();++it){
        cout<<*it<<"\n";
    }
    return 0;
}
