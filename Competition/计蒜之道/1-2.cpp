#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <set>
#define N 507
#define MAX 0x3f3f3f3f
using namespace std;
int v[N];
int c[N][N];
int n;
void Floyd(){
    long long i,j,k;
    for(k=1;k<=n;k++){
        for(j=1;j<=n;j++){
            for(i=1;i<=n;i++){
                c[j][i]=min(c[j][i],c[j][k]+c[k][i]);
            }
        }
    }
}
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int ans,a,b;
    while(scanf("%d",&n)!=EOF){
        memset(c,MAX,sizeof(c));
        ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&v[i]);
        }
        for(int i=1;i<=n-1;i++){
            scanf("%d%d",&a,&b);
            c[a][b]=c[b][a]=1;
        }
        Floyd();
        for(int i=1;i<n;i++){
            //cout<<"--------------\n";
            for(int j=i+1;j<=n;j++){
                //cout<<c[i][j]<<' ';
                if(gcd(v[i],v[j])==1){
                    ans+=c[i][j];
                }
            }
        }
        printf("%d\n",ans);
    }
}
