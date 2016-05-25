#include <bits/stdc++.h>
using namespace std;
struct  node{
    int num;
    int x;
}a[107];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main()
{
    int n,ans;
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&a[0].x);
        a[0].num=0;
        ans=0;
        for(int i=1;i<n;i++){
            scanf("%d",&a[i].x);
            a[i].num=i;
        }
        sort(a,a+n,cmp);
        while(a[n-1].num!=0){
            for(int i=0;i<n-1;i++){
                if(a[i].num==0){
                    ans++;
                    a[i].x+=1;
                    a[n-1].x-=1;
                    break;
                }
            }
            sort(a,a+n,cmp);
            //cout<<a[n-1].x<<' '<<a[n-1].num<<endl;
        }
        if(a[n-1].x==a[n-2].x){
            a[n-1].x+=1;
            a[n-2].x-=1;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
