#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int n,k,result;
int c[10];
string a[10];
void dfs(int now,int x){
    if(x == k){
        result++;
        return;
    }
    if(now==n){
        return;
    }
    for(int j=0;j<n;j++){//这一行填
        if(c[j]==0&&a[now][j]=='#'){
            c[j]=1;
            dfs(now+1,x+1);
            c[j]=0;
        }
    }
    dfs(now+1,x);//这一行不填
    return;
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==-1 && k==-1){
            break;
        }
        memset(c,0,sizeof(c));
        result = 0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        dfs(0, 0);
        printf("%d\n",result);
    }
    return 0;
}
