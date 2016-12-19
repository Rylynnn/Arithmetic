#include <bits/stdc++.h>
#define MAXN 1000007
#define MOD 1000000007
#define ll long long
using namespace std;
int main()
{
    //freopen("easy.in","r",stdin);
    //freopen("easy.out","w",stdout);
    int n,k,maxm;
    int a[15][15];
    while(scanf("%d%d",&n,&k)!=EOF){
        memset(a,0,sizeof(a));
        maxm=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i][0]);
            for(int j=1;j<=a[i][0];j++){
                scanf("%d",&a[i][j]);
            }
            for(int j=a[i][0]+1;j<=10;j++){
                a[i][j]=50;
            }
            maxm=max(maxm,a[i][0]);
        }
        int sum=0,ran=1,num=0;
        while(num<k){
            if(ran>maxm){
                break;
            }
            for(int i=1;i<=n;i++){
                if(num>k){
                    break;
                }
                if(a[i][ran]>=sum){
                    num++;
                    sum+=a[i][ran];
                }
            }
            ran++;
        }
        if(num<k){
            sum+=50*(k-num);
        }
        printf("%d\n",sum);
    }
}
