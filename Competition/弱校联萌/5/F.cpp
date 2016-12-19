#include <bits/stdc++.h>
#define N 2
#define MAX 100007
#define ll long long
#define M 20160519
using namespace std;
struct Mat{
    int m[N][N];
    void clear(){
        memset(m,0,sizeof(m));
    }
}tmp;
Mat mul(Mat& a,int la,Mat& b,int lb,int len,int MOD){
    Mat temp;
    for(int i=0;i<la;i++){
        for(int j=0;j<lb;j++){
            temp.m[i][j]=0;
            for(int k=0;k<len;k++){
                temp.m[i][j]+=((ll)a.m[i][k]*(ll)b.m[k][j])%MOD;
            }
        }
    }
    return temp;
}
Mat pow_mod(Mat& a,int la,int b,int MOD){
    Mat temp;
    temp.clear();
    for(int i=0;i<la;i++){
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
    int n,t;
    int MO;
    MO=26880696;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&n);
            Mat temp;
            temp.clear();
            tmp.clear();
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    if(i==0&&j==0){
                        tmp.m[i][j]=0;
                    }
                    else{
                        tmp.m[i][j]=1;
                    }
                }
            }
            int ans;
            temp=pow_mod(tmp,2,n-1,MO);
            ans=temp.m[1][1]%MO;
            //printf("%d\n",ans);
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    if(i==0&&j==0){
                        tmp.m[i][j]=0;
                    }
                    else{
                        tmp.m[i][j]=1;
                    }
                }
            }
            temp=pow_mod(tmp,2,ans-1,M);
            printf("%d\n",temp.m[1][1]%M);
        }
    }
}
