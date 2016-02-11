#include <bits/stdc++.h>
#define N 11000000
using namespace std;
int vis[N];
int main()
{
    int i,t,n;
    scanf("%d",&t);
    for(i=3; i<=N-10; i++){
        if (i%2==1){
            vis[i]=vis[i/2]+vis[i/2+1]+1;
        }
        else  vis[i]=2*vis[i/2];
    }
    while (t--)
    {
        cin>>n;
        cout<<vis[n]<<endl;
    }
    return 0;
}
