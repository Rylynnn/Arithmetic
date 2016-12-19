#include <bits/stdc++.h>
int main()
{
    int n,m;
    string s,p;
    scanf("%d",&t);
    while(t-->0){
        scanf("%d%d",&n,&m);
        cin>>s>>p;
        for(int i=0;i<n;i++){
            int j=0;
            if(s[i]==p[j]){
                dp[j][0]=1;
            }
            else if(s[i]==p[j+1]&&s[i+1]==p[j]){
                dp[j+1][1]=1;
            }
            else{
                continue;
            }
            for(int j=2;j<m;j+=2){
                if(s[i+j]==p[j]&&s[i+j+1]==p[j+1]){
                    dp
                }
            }
        }
    }
}
