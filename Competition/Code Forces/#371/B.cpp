#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[100007],ans,d;
set<int> q;
set<int>::iterator it;
int main()
{
    while(scanf("%d",&n)!=EOF){
        memset(a,0,sizeof(a));
        q.clear();
        ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            q.insert(a[i]);
        }
        memset(a,0,sizeof(a));
        int num=0;
        for(it=q.begin();it!=q.end();it++){
            a[num++]=*it;
            //cout<<a[num-1]<<' ';
        }
        if(num%2==1){
            int now;
            for(int i=0;i<num;i++){
                if(i==num/2){
                    now=a[i];
                    break;
                }
            }
            int p=0;//cout<<now<<a[1];
            int b=0;
            for(int i=0;i<num;i++){
                if(abs(a[i]-now)!=0&&b==0){
                    b=abs(a[i]-now);
                }
                else if(abs(a[i]-now)!=0&&b!=0){
                    if(abs(a[i]-now)!=b){
                        p=1;
                    }
                }
            }
            if(p==1){
                printf("NO\n");
            }
            else{
                printf("YES\n");
            }
        }
        else{
            if(num==2){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }

    }
    return 0;
}
