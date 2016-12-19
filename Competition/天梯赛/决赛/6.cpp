#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n;
    char a;
    string b;
    while(scanf("%d %c\n",&n,&a)!=EOF){
        getline(cin,b);
        int len;
        len=b.size();
        if(n<=len){
            for(int i=len-n;i<len;i++){
                cout<<b[i];
            }
            printf("\n");
        }
        else{
            for(int i=0;i<n-len;i++){
                cout<<a;
            }
            cout<<b<<endl;
        }
    }
    return 0;
}
