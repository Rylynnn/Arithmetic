#include <bits/stdc++.h>
#define eps 1e-6
#define MAX 100007
#define ll long long
using namespace std;
set<int>a,b;
set<int>::iterator it;
int main()
{
    int n,k;
    while(scanf("%d",&n)!=EOF){
        a.clear();
        b.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&k);
            a.insert(k);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&k);
            b.insert(k);
        }
        //cout<<a.size()<<' '<<b.size();
        if(a.size()!=b.size()){
            printf("NO\n");
            continue;
        }
        int p=0;
        for(it=a.begin();it!=a.end();it++){
            if(b.count(*it)==0){
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
