#include <bits/stdc++.h>
#define MAX 500008
#define ll long long
using namespace std;
string a;
int pos=0,minm[500009][3],maxm[500009][3];
int dfs(){
    int n=pos++,l=MAX,r=MAX;//r和l一定得赋初值为0
    if(a[n]=='0');//不能直接dfs（n+1）因为是要历遍整个序列
    else if(a[n]=='1'){
        l=dfs();
    }
    else if(a[n]=='2'){
        l=dfs();
        r=dfs();
    }
    maxm[n][0]=max(maxm[l][1]+maxm[r][2],maxm[l][2]+maxm[r][1])+1;
    maxm[n][1]=max(maxm[l][0]+maxm[r][2],maxm[l][2]+maxm[r][0]);
    maxm[n][2]=max(maxm[l][0]+maxm[r][1],maxm[l][1]+maxm[r][0]);
    minm[n][0]=min(minm[l][1]+minm[r][2],minm[l][2]+minm[r][1])+1;
    minm[n][1]=min(minm[l][0]+minm[r][2],minm[l][2]+minm[r][0]);
    minm[n][2]=min(minm[l][0]+minm[r][1],minm[l][1]+minm[r][0]);
    return n;
}
int main()
{
    while(cin>>a){
        memset(minm,0,sizeof(minm));
        memset(maxm,0,sizeof(maxm));
        dfs();

        printf("%d %d\n",max(maxm[0][0],max(maxm[0][1],maxm[0][2])),min(minm[0][0],min(minm[0][1],minm[0][2])));
    }
}
