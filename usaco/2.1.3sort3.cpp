
/*
ID:15829681
LANG:C++
TASK:sort3
*/
#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#define FRO
using namespace std;
int n;
int a[1007],m[1007],vis[4][4];
int main()
{
    #ifdef FRO
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    #endif // FRO
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(m,0,sizeof(m));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        m[i]=a[i];
    }
    sort(m+1,m+n+1);
    for(int i=1;i<=n;i++){
        if(m[i]==1){
            if(a[i]==2){
                vis[1][2]++;
            }
            else if(a[i]==3){
                vis[1][3]++;
            }
        }
        else if(m[i]==2){
            if(a[i]==1){
                vis[2][1]++;
            }
            else if(a[i]==3){
                vis[2][3]++;
            }
        }
        else if(m[i]==3){
            if(a[i]==1){
                vis[3][1]++;
            }
            else if(a[i]==2){
                vis[3][2]++;
            }
        }
    }
    printf("%d\n",vis[2][1]+vis[3][1]+((vis[1][2]>vis[2][1])?(vis[1][2]-vis[2][1]+vis[3][2]):(vis[2][1]-vis[1][2]+vis[2][3])));
}
