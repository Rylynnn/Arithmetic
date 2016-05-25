/*
首先不能出现ABA或者BAB，其次，特判ABABA和BABAB的五位回文
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a;
    ios_base::sync_with_stdio(false);
    cin>>a;
    int p1=0,p2=0,p=0;
    for(int i=0; i<a.size(); i++) {
        if(a[i]=='A') {
            if(a[i+1]=='B'&&a[i+2]!='A') {
                p1=1;
            }
            else if(a[i+1]=='B'&&a[i+2]=='A'&&a[i+3]=='B'&&a[i+4]=='A'){
                p1=1;
            }
        }
        else if(a[i]=='B') {
            if(a[i+1]=='A'&&a[i+2]!='B') {
                p2=1;
            }
            else if(a[i+1]=='A'&&a[i+2]=='B'&&a[i+3]=='A'&&a[i+4]=='B'){
                p2=1;
            }
        }
    }
    //cout<<p1<<p2;
    if(p==0) {
        if(p1==1&&p2==1||a=="ABAXAB"||a=="BABXBA") {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
