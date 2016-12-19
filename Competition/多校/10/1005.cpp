#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=200003;

int n,m;
int w[MAXN];
int a[MAXN],b[MAXN];
vector<int> open_rem,close_rem;
vector<int> open[MAXN],close[MAXN];
vector<int>::iterator it;
long long ans=0;

int main() {
    while(2==scanf("%d%d",&n,&m)) {
        open_rem.clear();
        close_rem.clear();
        for(int i=1;i<n;++i) {
            scanf("%d",w+i);
            open_rem.push_back(i);
            close_rem.push_back(i);
        }
        for(int i=1;i<=m;++i) {
            scanf("%d%d",a+i,b+i);
            if(a[i]>b[i]) {
                swap(a[i],b[i]);
            }
            open[i].clear();
            close[i].clear();
        }
        for(int i=1,j=m;i<=m;++i,--j) {
            for(it=lower_bound(open_rem.begin(),open_rem.end(),a[i]);it!=open_rem.end()&&(*it)<b[i];) {
                open[i].push_back(*it);
                open_rem.erase(it);
            }
            for(it=lower_bound(close_rem.begin(),close_rem.end(),a[j]);it!=close_rem.end()&&(*it)<b[j];) {
                close[j].push_back(*it);
                close_rem.erase(it);
            }
        }
        for(int i=1;i<=m;++i) {
            for(int j=open[i].size()-1;j>=0;--j) {
                ans+=w[open[i][j]];
            }
            printf("%I64d\n",ans);
            for(int j=close[i].size()-1;j>=0;--j) {
                ans-=w[close[i][j]];
            }
        }
    }
    return 0;
}
