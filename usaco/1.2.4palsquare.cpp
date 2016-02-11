/*
ID:15829681
LANG:C++
TASK:palsquare
*/
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#define LOCAL
typedef long long LL;
using namespace std;
int main()
{
    #ifdef LOCAL
        freopen("palsquare.in","r",stdin);
        freopen("palsquare.out","w",stdout);
    #endif // LOCAL
    LL b,i,e,num;
    string a,c,d;
    scanf("%lld",&b);
    for(i=1;i<=300;i++){
        e=i;
        num=e*e;
        a.clear();
        d.clear();
        while(num){
            if(num%b<10){
                a.push_back(num%b+'0');
            }
            else{
                a.push_back(num%b-10+'A');
            }
            num/=b;
        }
        c=a;
        reverse(a.begin(),a.end());
        if(c==a){
            while(e){
                if(e%b<10){
                    d.push_back(e%b+'0');
                }
                else{
                    d.push_back(e%b-10+'A');
                }
                e/=b;
            }
            reverse(d.begin(),d.end());
            cout<<d<<" "<<c<<endl;
        }
    }
    return 0;
}
