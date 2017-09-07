#include <bits/stdc++.h>
using namespace std;
string a,b;
map<string,int>m;
map<string,int>::iterator it;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(cin>>a){
        getchar();
        getline(cin,b);
        m[b]++;
    }
     for(it=m.begin();it!=m.end();++it)
        cout<<"mp[\""<<it->first<<"\"]="<<it->second<<";\n";
}
