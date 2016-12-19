#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int n,m;
    char a;
    scanf("%d %c",&n,&a);
    if(n%2==1){
        m=n/2+1;
    }
    else{
        m=n/2;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<a;
        }
        cout<<endl;
    }
    return 0;
}
