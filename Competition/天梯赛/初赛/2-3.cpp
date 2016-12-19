#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN=105;

int n,cnt=1,root;
int inod[35],bacod[35];
int q[35],head,tail;

struct Node {
    int lson,rson;
    int c;
}tr[35];


int dfs(int bl,int br,int il,int ir) {
    if(bl==br) {
        tr[cnt].lson=tr[cnt].rson=-1;
        tr[cnt].c=bacod[br];
        return cnt++;
    }
    for(int i=il;i<=ir;++i) {
        if(bacod[br]==inod[i]) {
            int cur=cnt++;
            tr[cur].lson=tr[cur].rson=-1;
            tr[cur].c=bacod[br];
            if(il<i) {
                tr[cur].lson=dfs(bl,bl+i-il-1,il,i-1);
            }
            if(i<ir) {
                tr[cur].rson=dfs(bl+i-il,br-1,i+1,ir);
            }
            return cur;
        }
    }
    return cnt;
}

void print(int root) {
    printf("%d",tr[root].c);
    int cur;
    head=tail=0;
    if(tr[root].lson!=-1) {
        q[tail++]=tr[root].lson;
    }
    if(tr[root].rson!=-1) {
        q[tail++]=tr[root].rson;
    }

    while(head!=tail) {
        cur=q[head++];
        printf(" %d",tr[cur].c);
        if(tr[cur].lson!=-1) {
            q[tail++]=tr[cur].lson;
        }
        if(tr[cur].rson!=-1) {
            q[tail++]=tr[cur].rson;
        }
    }
    printf("\n");
}

int main() {
    while(1==scanf("%d",&n)) {
        for(int i=0;i<n;++i) {
            scanf("%d",bacod+i);
        }
        for(int i=0;i<n;++i) {
            scanf("%d",inod+i);
        }
        cnt=0;
        print(dfs(0,n-1,0,n-1));
    }
    return 0;
}

