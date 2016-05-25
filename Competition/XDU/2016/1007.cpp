#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
int root,sum;
int n,k;
const int maxn=100000;
struct lf
{
    int dist;
    LL key;
    int left,right;
}nd[maxn];
int merge(int a,int b)
{
    int c;
    if ((a==0)||((b!=0)&&(nd[a].key>nd[b].key))) swap(a,b);
    if (b==0) return a;
    nd[a].right=merge(nd[a].right,b);
    if (nd[nd[a].left].dist<nd[nd[a].right].dist) swap(nd[a].left,nd[a].right);
    nd[a].dist=nd[nd[a].right].dist+1;
    return a;
}
LL ans;
int main()
{
    while (cin>>n>>k)
    {
        ans=0;
        root=sum=0;
        for (int i=1;i<=n;i++)
        {
            LL x;
            scanf("%lld",&x);
            sum++;
            nd[sum].dist=nd[sum].left=nd[sum].right=0;
            nd[sum].key=x;
            root=merge(root,sum);
        }
        int flag=0;
        while (1)
        {
            LL num=0;
            for (int i=1;i<=k;i++)
            {
                if (root==0)
                {
                    flag=1;
                    break;
                }
                num+=nd[root].key;
                root=merge(nd[root].left,nd[root].right);
            }
            ans+=num;
            if (flag) break;
            if (root==0) break;
            sum++;
            nd[sum].dist=nd[sum].left=nd[sum].right=0;
            nd[sum].key=num;
            root=merge(root,sum);
        }
        cout<<ans<<endl;
    }
    return 0;
}
