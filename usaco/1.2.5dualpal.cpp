/*
ID:15829681
LANG:C++
TASK:dualpal
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
        freopen("dualpal.in","r",stdin);
        freopen("dualpal.out","w",stdout);
    #endif // LOCAL
    LL b,i,j,e,n,s,num,p,d[20];
    string a,c;
    scanf("%lld%lld",&n,&s);
    num=0;
    i=s+1;
    while(num<=n){
        p=0;
        for(b=2;p!=2,b<=10;b++){
            e=i;
            a.clear();
            while(e){
                a.push_back(e%b+'0');
                e/=b;
            }
            c=a;
            reverse(a.begin(),a.end());
            if(c==a){
                if(!p){
                    p=1;
                }
                else{
                    p=2;
                }
            }
        }
        if(p==2){
            num++;
            d[num]=i;
        }
        i++;
    }
    sort(d+1,d+1+n);
    for(j=1;j<=n;j++){
        printf("%lld\n",d[j]);
    }
    return 0;
}
