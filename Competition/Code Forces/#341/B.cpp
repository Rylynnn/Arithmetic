#include <bits/stdc++.h>
using namespace std;
int node[1007][1007];
long long p=10000007;
int coun=0;
int  comb1(int m,int k)//(C(m,k))
{
    int i;
    for (i=m; i>=k; i--)
    {
        if (k>1)
        {
            comb1(i-1,k-1);
        }
        else
        {
            coun++;
            //cout<<coun;
        }
    }


    return coun;
}
int main()
{
    cout<<comb1(3,2);
    int n,i,j,a,b,now;
    long long ans,num;
    while(scanf("%d",&n)!=EOF) {
        ans=0;
        memset(node,0,sizeof(node));
        for(i=1; i<=n; i++) {
            scanf("%d%d",&a,&b);
            node[a][b]=1;
        }
        for(i=1; i<=1000; i++) {
            num=0;
            now=i;
            for(j=1; j<=1000; j++) {
                if(now<=1000&&node[now++][j]) {
                    num++;
                    //cout<<now<<' '<<j;
                }
            }
            //printf("%I64d",num);
            ans+=comb1(num,2);
        }
        for(i=2; i<=1000; i++) {
            num=0;
            now=i;
            for(j=1; j<=1000; j++) {
                if(now<=1000&&node[j][now++]) {
                    num++;
                    //cout<<j<<' '<<now;
                }
            }
            //printf("%I64d",num);
            ans+=comb1(num,2);
        }
        for(i=1; i<=1000; i++) {
            num=0;
            now=i;
            for(j=1000; j>=1; j--) {
                if(now<=1000&&node[now++][j]) {
                    num++;
                    //cout<<now<<' '<<j;
                }
            }
            //printf("%I64d",num);
            ans+=comb1(num,2);
        }
        for(i=2; i<=1000; i++) {
            num=0;
            now=i;
            for(j=1000; j>=1; j--) {
                if(now<=1000&&node[now++][j]) {
                    num++;
                    //cout<<now<<' '<<j;
                }
            }
            //printf("%I64d",num);
            ans+=comb1(num,2);
        }
        printf("%I64d\n",ans);
    }
    return 0;
