#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct node{
    string a;
    int num;
}b[110];
bool cmp(node c,node d){
    if(c.num==d.num){
        return c.a>d.a;
    }
    else{
        return c.num>d.num;
    }
}
int main()
{
    int n,i,m,j;
    string c;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(i=1;i<110;i++){
            b[i].num=0;
            b[i].a="";
        }
        for(i=1;i<=m;i++){
            while(1){
                getline(cin,c);//要加while！！！！！因为getline会先吃上一个缓冲区中的\n
                if(c!=""&&c!="\n"){
                    break;
                }
            }
            for(j=c.size()-4;j<c.size();j++){
                b[i].num=b[i].num*10+c[j]-'0';
            }
            b[i].a=c.substr(0,c.size()-5);
        }
        sort(b+1,b+1+m,cmp);
        for(i=1;i<=m;i++){
            cout<<b[i].a<<endl;
        }
    }
    return 0;
}
