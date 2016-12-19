#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>
#define maxn 105
using namespace std;
string str;
struct node{
    set<string> h;
    map<string,node*>mp;
    node(){
        h.clear();
        mp.clear();
    }
};
node* push(node* pre,string now,int p){
    if(!p){
        pre->h.insert(now);
        return NULL;
    }
    else{
        if(pre->mp.count(now)==0){
            pre->mp[now]=new(node);
            return pre->mp[now];
        }
    }
}
void dostr(node* r){
    node *pre=r;
    string now;
    now.clear();
    for(int i=0;i<str.size();i++){
        if(str[i]!='/'){
            now.push_back(str[i]);
        }
        else{
            now.push_back('\0');
            pre=push(pre,now,1);
            now.clear();
        }
    }
    now.push_back('\0');
    push(pre,now,0);
}
map<string,node*>::iterator it;
set<string>::iterator is;
void dfs(node *cur,int num)
{
    for(it=cur->mp.begin();it!=cur->mp.end();it++){
        for(int i=1;i<=num-1;i++){
            cout<<"    ";
        }
        cout<<it->first<<endl;
        dfs(it->second,num+1);
    }
    for(is=cur->h.begin();is!=cur->h.end();is++)
    {
        for(int i=1;i<=num-1;i++){
            cout<<"    ";
        }
        cout<<*is<<endl;
    }
    delete(cur);
}
int main(){
    int kase=1;
    node *r;
    r=new(node);
    while(getline(cin,str)){
            if(str[0]=='0'&&str.size()==1){
                printf("Case %d:\n",kase++);
                dfs(r,1);
                r=new(node);
                continue;
            }
            dostr(r);
    }
    return 0;
}
