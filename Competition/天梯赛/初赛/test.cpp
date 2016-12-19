#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
    int index,num,money;

    bool operator < (const Node& a) const {
        if(money!=a.money) {
            return money>a.money;
        }
        return num>a.num||(index<a.index);
    }
}people[10005];

int n,k,nn,pp;

int main() {
    while(1==scanf("%d",&n)) {
        for(int i=1;i<=n;++i) {
            people[i].index=i;
            people[i].num=0;
            people[i].money=0;
        }
        for(int i=1;i<=n;++i) {
            scanf("%d",&k);
            while(k-->0) {
                scanf("%d%d",&nn,&pp);
                people[i].money-=pp;
                people[nn].money+=pp;
                ++people[nn].num;
            }
        }
        sort(people+1,people+1+n);
        for(int i=1;i<=n;++i) {
            printf("%d %.2f\n",people[i].index,0.01*people[i].money);
        }
    }
    return 0;
}
