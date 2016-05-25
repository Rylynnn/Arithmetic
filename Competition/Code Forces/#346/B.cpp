#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int n;
    int sco;
} par[100007];
bool cmp(node a,node b) {
    if(a.n!=b.n) {
        return a.n<b.n;
    }
    else {
        return a.sco<b.sco;
    }
}
int num[10007];
int main()
{
    int n,m;
    string b;
    while(scanf("%d%d",&n,&m)!=EOF) {
        memset(num,0,sizeof(num));
        for(int i=0; i<n; i++) {
            cin>>par[i].name>>par[i].n>>par[i].sco;
            num[par[i].n]++;
        }
        sort(par,par+n,cmp);
        int k=1;
        for(int i=0; i<n; i+=num[k++]) {
            if(num[k]==2) {
                cout<<par[i+num[k]-1].name<<' '<<par[i+num[k]-2].name<<endl;
            }
            else {
                if(par[i+num[k]-3].sco!=par[i+num[k]-2].sco) {
                    cout<<par[i+num[k]-1].name<<' '<<par[i+num[k]-2].name<<endl;
                }
                else {
                    cout<<'?'<<endl;
                }
            }
        }
    }
    return 0;
}
