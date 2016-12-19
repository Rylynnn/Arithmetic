#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,now,a[107],cnt;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int ans;
        now=10;
        cnt=0;
        ans=0;
        int i;
        for(i=0;i<n;i++){
            now+=a[i];
            if(now<360){
                cnt++;
            }
            else if(now>=360){
                if(now>720){
                    break;
                }
                else{
                    cnt++;
                    ans+=now-360;
                }
            }
        }
        printf("%d %d\n",cnt,ans);
    }
    return 0;
}
