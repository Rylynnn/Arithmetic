#include <bits/stdc++.h>
#define eps 1e-6
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    int n,b,m;
    vector<int>a;
    vector<int>::iterator it;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&b);
            a.push_back(b);
        }
        sort(a.begin(),a.end());
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&b);
            it=upper_bound(a.begin(),a.end(),b);
            if(*it==b){
                cout<<it-a.begin()-1<<endl;
            }
            else{
                cout<<it-a.begin()<<endl;
            }
        }
    }
}
