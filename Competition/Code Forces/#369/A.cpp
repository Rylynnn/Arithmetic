#include <bits/stdc++.h>
#define MaX 500008
#define ll long long
using namespace std;
int main()
{
    int n;
    string a[1007];
    while(scanf("%d",&n)!=EOF){
        int p=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(p==0&&((a[i][0]==a[i][1]&&a[i][0]=='O')||(a[i][4]==a[i][3]&&a[i][4]=='O'))){
                p=1;
                if((a[i][0]==a[i][1]&&a[i][0]=='O')){
                    a[i][0]=a[i][1]='+';
                }
                else{
                    if(a[i][4]==a[i][3]&&a[i][4]=='O'){
                    a[i][4]=a[i][3]='+';
                    }
                }
            }
        }
        if(p==1){
            printf("YES\n");
            for(int i=0;i<n;i++){
                cout<<a[i]<<endl;
            }
        }
        else{
            printf("NO\n");
        }
    }
}
