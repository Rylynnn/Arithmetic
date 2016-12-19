#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    while(cin>>a){
        if(a=="0"){
            break;
        }
        int len=a.size();
        if(len<8||len>16){
            printf("NO\n");
            continue;
        }
        int p1=0,p2=0,p3=0,p4=0;
        for(int i=0;i<len;i++){
            if(a[i]>='A'&&a[i]<='Z'){
                p1=1;
            }
            else if(a[i]>='a'&&a[i]<='z'){
                p2=1;
            }
            else if(a[i]>='0'&&a[i]<='9'){
                p3=1;
            }
            else if(a[i]=='~'||a[i]=='!'||a[i]=='@'||a[i]=='#'||a[i]=='$'||a[i]=='%'||a[i]=='^'){
                p4=1;
            }
        }
        if(p1+p2+p3+p4>=3){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

    }
    return 0;
}
