#include <string>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int n,k,sum;
char m[10][10];
int c[10],r[10];
void dfs(int num,int x){
    if(num==0){
        sum++;
        for(int i=0;i<n;i++){
        cout<<m[i]<<endl;
    }
    cout<<endl;
        return;
    }
    for(int i=x+1;i<n-num+1;i++){//一层一层循环所以只需要更改列就行
        for(int j=0;j<n;j++){
            if(m[i][j]=='#'&&c[j]==0&&r[i]==0){
                m[i][j]='.';
                c[j]=1;
                r[i]=1;
                dfs(num-1,x+1);
                m[i][j]='#';
                c[j]=0;
                r[i]=0;
            }
        }
    }
    return;
}
int main()
{
    //ios::sync_with_stdio(false);
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==-1&&k==-1){
            break;
        }
        memset(c,0,sizeof(c));
        memset(r,0,sizeof(r));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf(" %c",&m[i][j]);
            }
        }
        sum=0;
        dfs(k,-1);
        printf("%d\n",sum);
    }
    return 0;
}
