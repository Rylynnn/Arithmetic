/*
ID:15829681
LANG:C++
TASK:sprime
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
#define STA
#define LL long long
//指数的数目估计错误
bool YES(int it){
    for(int i=3;i*i<it;i+=2)
        if(it%i==0)
            return false;
    return true;
}
int prime[9][5007];
int main()
{
    #ifdef STA
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    #endif // STA
    int i,j,k,n;
    int tail[5]={0,1,3,7,9};
    memset(prime,0,sizeof(prime));
    int length[9];
    memset(length,0,sizeof(length));
    length[1]=4;
    prime[1][1]=2,prime[1][2]=3,prime[1][3]=5,prime[1][4]=7;
    for(i=1;i<8;i++){
        for(j=1;j<=length[i];j++){
            for(k=1;k<=4;k++){
                if(YES(prime[i][j]*10+tail[k])){
                    prime[i+1][++length[i+1]]=prime[i][j]*10+tail[k];
                }
            }
        }
    }
    scanf("%d",&n);
    for(i=1;i<=length[n];i++){
        printf("%d\n",prime[n][i]);
    }
    return 0;
}
