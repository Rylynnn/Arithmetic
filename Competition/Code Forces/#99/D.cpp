#include <bits/stdc++.h>
using namespace std;
int n[2][10],m[2][10];
int calzero(){
    int sum=0;
    for(int i=0;i<=5;i++){
        sum+=min(n[0][i],n[1][9-i]);
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    string a;
    string ans;
    while(cin>>a){
        int num;
        ans.clear();
        memset(m,0,sizeof(m));
        memset(n,0,sizeof(n));
        for(int i=0;i<a.size();i++){
            n[0][a[i]-'0']++;
            n[1][a[i]-'0']++;

            m[0][a[i]-'0']++;
            m[1][a[i]-'0']++;
        }
        int maxn=-1,cur=0;
        for(int i=1;i<=5;i++){
            if(n[0][i]>=1&&n[1][10-i]>=1){//如果不存在可以构成10的数则直接把0放在最后输出
                n[0][i]--;
                n[1][10-i]--;
                num=calzero();
                //cout<<num<<endl;
                if(num>maxn){
                    maxn=num;
                    cur=i;
                }
                n[0][i]++;
                n[1][10-i]++;
            }
        }
        if(maxn==-1){
            for(int i=9;i>=0;i--){
                for(int j=0;j<n[0][i];j++){
                    cout<<i;
                }
            }
            cout<<"\n";
            for(int i=9;i>=0;i--){
                for(int j=0;j<n[0][i];j++){
                    cout<<i;
                }
            }
            cout<<"\n";
        }
        else{
            n[0][cur]--;
            n[1][10-cur]--;
            int now=n[0][0]-n[0][9];
            if(cur==1){//特判：如果最后为1+9等于10，则有一个0是应该放在末尾的
                now++;
            }
            for(int i=0;i<now;i++){
                ans.push_back('0');
            }
            if(now>0){
                n[0][0]-=now;
            }
            ans.push_back(cur+'0');
            for(int i=0;i<=9;i++){
                int minm=min(n[0][i],n[1][9-i]);
                for(int j=0;j<minm;j++){
                    ans.push_back(i+'0');
                }
                n[0][i]-=minm;
            }
            for(int i=1;i<=9;i++){
                for(int j=0;j<n[0][i];j++){
                    ans.push_back(i+'0');
                }
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";

            ans.clear();
            m[0][cur]--;
            m[1][10-cur]--;
            for(int i=0;i<m[1][0]-m[1][9];i++){
                ans.push_back('0');
            }
            if(m[1][0]-m[1][9]>0){
                m[1][0]-=(m[1][0]-m[1][9]);
            }
            ans.push_back((10-cur)+'0');
            for(int i=0;i<=9;i++){
                int minm=min(m[0][i],m[1][9-i]);
                for(int j=0;j<minm;j++){
                    ans.push_back((9-i)+'0');
                }
                m[1][9-i]-=minm;
            }
            for(int i=1;i<=9;i++){
                for(int j=0;j<m[1][i];j++){
                    ans.push_back(i+'0');
                }
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";
        }
    }
}
