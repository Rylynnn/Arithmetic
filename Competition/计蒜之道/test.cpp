#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN=505;

int n,s,e,ans;
int val[MAXN],dis[MAXN];
int q[MAXN],head,tail;
bool vis[MAXN];
vector<int> g[MAXN];

int main() {
    while(1==scanf("%d",&n)) {
        for(int i=1;i<=n;++i) {
            scanf("%d",val+i);
            g[i].clear();
        }
        for(int i=1;i<n;++i) {
            scanf("%d%d",&s,&e);
            g[s].push_back(e);
            g[e].push_back(s);
        }
        ans=0;
        for(int i=1;i<=n;++i) {
            memset(dis,-1,sizeof(dis));
            head=tail=0;
            q[tail++]=i;
            dis[i]=0;
            while(head!=tail) {
                s=q[head++];
                for(int j=g[s].size()-1;j>=0;--j) {
                    e=g[s][j];
                    if(dis[e]==-1) {
                        q[tail++]=e;
                        dis[e]=dis[s]+1;
                        if(1==__gcd(val[i],val[e])) {
                            ans+=dis[e];
                        }
                    }
                }
            }
        }
        printf("%d\n",ans>>1);
    }
    return 0;
}
