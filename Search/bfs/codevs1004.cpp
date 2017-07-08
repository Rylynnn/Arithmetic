#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MOD 987654321
using namespace std;
string a[4],s;
int h[],num[16];
void calhash(string b){
    int ans=0;
    for(int i=0;i<16;i++){
        if(b[i]=='0'){
            continue;
        }
        else if(b[i]=='1'){
            ans+=num[15-i];
            ans%=MOD;
        }
        else if(b[i]=='2'){
            ans+=2*num[15-i];
            ans%=MOD;
        }
    }
    return ans;
}
void bfs(){

}
int main()
{
    num[0]=1;
    for(int i=1;i<16;i++){
        num[i]=num[i-1]*3;
    }
    for(int i=0;i<4;i++){
        cin>>a[i];
        for(int j=0;j<4;j++){
            if(a[i]=='O'){
                s+="0";
            }
            else if(a[i]=='B'){
                s+="1";
            }
            else if(a[i]=='W'){
                s+="2";
            }
        }
    }
    bfs();
}
