#include <bits/stdc++.h>
#define ll long long
using namespace std;
set<int>H;
int ans[1000007];
int main()
{
    ll n,m;
    ll a,num;
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        num=0;
        H.clear();
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a);
            H.insert(a);
        }
        int i=1;
        while(m>=i){
            if(H.find(i)==H.end()){
                m-=i;
                //cout<<i<<' '<<m;
                H.insert(i);
                ans[num++]=i;
                //cout<<ans[num-1];
            }
            i++;
        }
        if(num!=0){
            printf("%I64d\n",num);
            printf("%I64d",ans[0]);
            for(int i=1;i<num;i++){
                printf(" %I64d",ans[i]);
            }
            printf("\n");
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
