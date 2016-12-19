#include <bits/stdc++.h>
#define N 2
#define M 1000000009
#define ll long long
using namespace std;
struct Mat{
    ll m[N][N];
    void clear(){
        memset(m,0,sizeof(m));
    }
}tmp;
Mat mul(Mat& a,ll la,Mat& b,ll lb,ll len,ll MOD){
    Mat temp;
    for(ll i=0;i<la;i++){
        for(ll j=0;j<lb;j++){
            temp.m[i][j]=0;
            for(ll k=0;k<len;k++){
                temp.m[i][j]+=a.m[i][k]*b.m[k][j];
                temp.m[i][j]%=MOD;
            }
        }
    }
    return temp;
}
Mat pow_mod(Mat& a,ll la,ll b,ll MOD){
    Mat temp;
    temp.clear();
    for(ll i=0;i<la;i++){
        temp.m[i][i]=1;
    }
    while(b){
        if(b&1){
            temp=mul(temp,la,a,la,la,MOD);
        }
        a=mul(a,la,a,la,la,MOD);
        b>>=1;
    }
    return temp;
}
int main()
{
    ll n;

    while(scanf("%I64d",&n)!=EOF){
        if(n==0){
            printf("0\n");
        }
        Mat temp;
        temp.clear();
        for(ll i=0;i<2;i++){
            for(ll j=0;j<2;j++){
                if(i==0&&j==0){
                    tmp.m[i][j]=0;
                }
                else{
                    tmp.m[i][j]=1;
                }
            }
        }
        ll f[2]={0,1},ans[2];
        memset(ans,0,sizeof(ans));
        temp=pow_mod(tmp,2,n-1,M);
        for(ll j=0;j<2;j++){
            ans[j]=0;
            for(ll k=0;k<2;k++){
                ans[j]+=f[k]*temp.m[k][j];
                ans[j]%=M;
            }
        }
        printf("%I64d\n",ans[1]);
    }
}
