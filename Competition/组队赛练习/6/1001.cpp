#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string a,b;
int main()
{
    //freopen("in.txt","r",stdin);
    a="doge";
    long long p,num=0;;
    while(cin>>b){
        for(int i=0;i<b.size();i++){
            if(b[i]>='A'&&b[i]<='Z'){
                b[i]=b[i]-'A'+'a';
            }
        }
        for(int i=0;i<b.size();i++){
            p=0;
            for(int j=0;j<a.size();j++){
                if(a[j]!=b[i+j]){
                    p=1;
                    break;
                }
            }
            if(p==0){
                num++;
            }
        }
    }
    printf("%I64d\n",num);
    return 0;
}
