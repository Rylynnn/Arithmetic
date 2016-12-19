#include <bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator() (const int& a,const int& b){
        if(a!=b){
            return a>b;
        }
        else{
            return a>b;
        }
    }
};
set<int,cmp>s;
int h[1000007],a[1000007],ans;
set<int,cmp>::iterator it;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(h,0,sizeof(h));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            for(int j=1;j*j<=a[i];j++){
                if(a[i]%j==0){
                    h[j]++;
                    h[a[i]/j]++;
                    s.insert(j);
                    s.insert(a[i]/j);
                }
            }
        }
        for(it=s.begin();it!=s.end();it++){
            if(h[*it]>=2){
                ans=*it;
                break;
            }
        }
        printf("%d\n",ans);
    }
}
