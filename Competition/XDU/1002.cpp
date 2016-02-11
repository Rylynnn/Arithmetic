#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#define N 10100
using namespace std;
struct rating{
    string s;
    int rate;
}p[N];

bool cmp(const rating& a,const rating& b) {
    if(a.rate!=b.rate)
        return a.rate>b.rate;
    return a.s<b.s;
}
int main()
{
    int n,i;
    while(~scanf("%d",&n)&&n!=0){
        for(i=0;i<n;i++){
            cin>>p[i].s;
            scanf("%d",&p[i].rate);
        }
        sort(p,p+n,cmp);
        for(i=0;i<n;i++){
            cout<<p[i].s;
            printf(" %d\n",p[i].rate);
        }
    }
}
