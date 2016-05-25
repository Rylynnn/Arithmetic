#include <bits/stdc++.h>
using namespace std;
int h[30];
int main(){
    int n,ans;
    string a;
    while(scanf("%d",&n)!=EOF){
        cin>>a;
        ans=0;
        memset(h,0,sizeof(h));
        for(int i=0;i<n;i++){
            h[a[i]-'a']++;
        }
        if(n>26){
            printf("-1\n");
        }
        else{
            for(int i=0;i<26;i++){
                if(h[i]!=0){
                    ans+=h[i]-1;
                }
            }
            printf("%d\n",ans);
        }
    }
}
