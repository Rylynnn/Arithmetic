#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <cmath>
#define MAX 50008
#define lson (t<<1)
#define rson (t<<1|1)
using namespace std;
int dp[200067][20],a[200067],n;
void st(){
    for(int j=1;(1<<j)<=n;j++){
        //cout<<2;
        for(int i=1;i+(j<<1)-1<=n;i++){
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
            //cout<<dp[i][j]<<' ';
        }
    }
}
int query(int s,int v){
    int k=(int)(log(v-s+1.0)/log(2.0));
    return max(dp[s][k],dp[v-(1<<k)+1][k]);
}
int bsearch(int l,int r){
    int temp=a[r];
    while(l<r){
        int mid=(l+r)>>1;
        if(a[mid]>=temp){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return r;
}
int main()
{
    int q;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        scanf("%d",&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        dp[n][0]=1;
        int temp=1;
        for(int i=n-1;i>0;i--){//众数所以倒着从后往前存每个数从i开始的出现最多的次数
            if(a[i]==a[i+1]){
                temp++;
            }
            else{
                temp=1;
            }
            dp[i][0]=temp;
        }
        st();
        while(q--){
            int s,t;
            scanf("%d%d",&s,&t);
            int temp=bsearch(s,t);
            int ans=t-temp+1;
            t=temp-1;
            if(t<s)
                printf("%d\n",ans);
            else
                printf("%d\n",max(ans,query(s,t)));
        }/*因为是倒着存从i开始的出现的最多的次数，所以如果直接询问的话会造成如果整个区间的值一样，
        而如果后面还有相同的数不在这个区间内，那么直接求该区间的dp的最值就是错的，所以要对跟区间最
        右边值相同的数单独扫一遍处理。*/
    }
    return 0;
}
