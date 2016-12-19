/*
hack：我在计算最小值的时候直接算的个数竟然也能过样例。。。。。。
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    string a[107],cor;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        cin>>cor;
        int p[107];
        memset(p,0,sizeof(p));
        int minm=0,maxm=0,num=0;
        for(int i=0;i<n;i++){
            if(a[i].size()<cor.size()){
                minm++;
                num++;
                if(num==k){
                    minm+=5;
                    num=0;
                }
            }
            if(a[i].size()>cor.size()){
                p[i]=1;
            }
        }
        minm++;
        int ans=0;
        num=0;
        for(int i=0;i<n;i++){
            if(p[i]==0&&a[i]!=cor){
                ans++;
                num++;
                if(num==k){
                    ans+=5;
                    num=0;
                }
            }
        }
        ans++;
        printf("%d %d\n",minm,ans);
    }
}
