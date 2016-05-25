#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    int x[30],y[30],xx[200],yy[200];
    while(cin>>a>>b){
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        memset(xx,0,sizeof(xx));
        memset(yy,0,sizeof(yy));
        if(a.size()!=b.size()){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<a.size();i++){//每个字母出现了几次
            x[a[i]-'A']++;
            y[b[i]-'A']++;
        }
        for(int i=0;i<26;i++){//出现次数相同的字母有多少个
            xx[x[i]]++;
            yy[y[i]]++;
        }
        int p=0;
        for(int i=0;i<200;i++){
            if(xx[i]!=yy[i]){
                p=1;
            }
        }
        if(p==1){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
