#include <bits/stdc++.h>
using namespace std;
int n;
int a[25];
bool prime(int i){
    if(i==2||i==3||i==5||i==7||i==11||i==13||i==17||i==19||i==23||i==29||i==31||i==37){
        return true;
    }
    return false;
}
void dfs(int a[],int t){
    int i,j,p;
    if(t==n+1&&prime(a[1]+a[n])){
        for(i=1;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n]);
        return;
    }
    //cout<<t<<n;
    for(i=2;i<=n;i++){
        a[t]=i;
        p=0;
        for(j=1;j<t;j++){//ШЅжи
            if(a[j]==a[t]){
                p=1;
            }
        }
        if(p==0&&prime(a[t]+a[t-1])){
            //printf("%d",a[t]);
            dfs(a,t+1);
        }
    }
}
int main()
{
    int num=0;
    while(scanf("%d",&n)!=EOF){
        //cout<<n;
        printf("Case %d:\n",++num);
        if(n&1){
            printf("\n");
        }
        else{
            a[1]=1;
            dfs(a,2);
        }
    }
    return 0;
}
