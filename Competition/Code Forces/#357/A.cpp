#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int p=0;
        string a;
        int b,c;
        while(n--){
            cin>>a>>b>>c;
            if(b>=2400&&c>b){
                p=1;
            }
        }
        if(p==1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
