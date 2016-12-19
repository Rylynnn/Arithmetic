#include <bits/stdc++.h>
using namespace std;
vector<int>a;
bool cmp(int a,int b){
    return a<b;
}
int main()
{
    int n,b;
    while(scanf("%d",&n)!=EOF){
        a.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&b);
            a.push_back(b);
        }
        sort(a.begin(),a.end(),cmp);
        vector<int>::iterator loc;
        int i;
        for(i=1;;i++){
            loc=lower_bound(a.begin(),a.end(),i);
            if(loc!=a.end()){
                *loc=i;
                continue;
            }
            else{
                break;
            }
        }
        printf("%d\n",i);
    }
    return 0;
}
