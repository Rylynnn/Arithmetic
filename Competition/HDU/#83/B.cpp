#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
set <long long> q;
long long ans,vis[10];
void dfs(int b,int a) {
    if(a==b) {
        //cout<<ans<<' ';
        q.insert(ans);
        return;
    }
    if(vis[4]<a/2) {
        ans=ans*10+4;
        vis[4]++;
        dfs(b+1,a);
        ans/=10;
        vis[4]--;
    }
    if(vis[7]<a/2) {
        ans=ans*10+7;
        vis[7]++;
        dfs(b+1,a);
        ans/=10;
        vis[7]--;
    }
}
int main()
{
    //freopen("out.txt","w",stdout);
    long long t,n;
    ans=0;
    q.clear();
    for(int i=2; i<=18; i+=2) {//比1e18要大的应该至少有20位
        ans=0;
        vis[4]=0,vis[7]=0;
        dfs(0,i);
    }
    //for (std::set<long long>::iterator it=q.begin(); it!=q.end(); ++it)
    //std::cout << ' ' << *it;
    while(scanf("%lld",&t)!=EOF){
        while(t--){
            scanf("%lld",&n);
            //std::set<long long>::iterator it=q.end()-1;
            if(n>777777777444444444){
                printf("44444444447777777777\n");
            }
            else{
                printf("%lld\n",*q.lower_bound(n));
            }
        }
    }
    return 0;
}
