#include <bits/stdc++.h>
using namespace std;
string s;
bool check(int i,int k){
    string a,b;
    a=s.substr(i,k);
    b.assign(a.rbegin(), a.rend());
    if(a==b){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    int num,len,lenth,i;
    cin>>s;
    len=s.size();
    scanf("%d",&num);
    if(len%num!=0){
        printf("NO\n");
    }
    else{
        lenth=len/num;
        int p=0;
        for(i=0;i<len;i+=lenth){
            if(!check(i,lenth)){
                p=1;
                break;
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
