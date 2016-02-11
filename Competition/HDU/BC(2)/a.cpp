#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n,anum,bnum,i;
    string a;
    while(scanf("%d",&n)!=EOF){
    while(n--){
        cin>>a;
        anum=bnum=0;
        for(i=0;i<a.size();i++){
            if(a[i]=='('){
                anum++;
            }
            else{
                bnum++;
            }
        }
        printf("%d\n",min(bnum,anum));
    }
    }
}
