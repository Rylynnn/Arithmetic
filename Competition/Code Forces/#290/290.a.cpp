#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,m,i;
    string s1 = "",s2 = "",s3 = "";
    cin >> n >> m;
    for(i = 0; i < m; i++){
        s1 += '#';
        s2 += '.';
        s3 += '.';
    }
    s2[m-1] = '#';
    s3[0] = '#';
    for(i = 0; i < n; i++){
        if(i%4 == 0 || i%4 == 2){
            cout << s1 << endl;
        }
        if(i%4 == 1){
            cout << s2 <<endl;
        }
        if(i%4 == 3){
            cout << s3 <<endl;
        }
    }
    return 0;
}
