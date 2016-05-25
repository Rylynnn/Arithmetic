#include <bits/stdc++.h>
using namespace std;
int main(){
    string a;
    int b[4],n;
    a.clear();
    for(int i=1;i<=1000;i++){
        int j=i;
        int k=0;
        memset(b,0,sizeof(b));
        while(j){
            b[k]=j%10;
            j/=10;
            k++;
        }
        for(int q=k-1;q>=0;q--){
            a+=b[q]+'0';
        }
    }
    //cout<<a<<endl;
    while(scanf("%d",&n)!=EOF){
        cout<<a[n-1]<<endl;
    }
    return 0;
}
