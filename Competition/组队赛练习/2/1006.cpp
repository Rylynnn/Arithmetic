/*
由于矩阵太大，函数返回矩阵的话oj直接判CE，只能用全局变量
T:mul()函数的变量没设置对
*/
#include <bits/stdc++.h>
#define N 1001
using namespace std;
struct matrix{
    int x[N][N];
    void clear(){
        memset(x,0,sizeof(x));
    }
}tmp,ppp,a,b,c;
int mm;
int n,k;
long long ans;
void mul(matrix& a,int ab,matrix& b,int bb,int tmpb,int MOD){
    tmp.clear();
    for(int i=0;i<ab;i++){
        for(int j=0;j<bb;j++){
            for(int k=0;k<tmpb;k++){
                tmp.x[i][j]=(tmp.x[i][j]+a.x[i][k]*b.x[k][j])%MOD;
            }
        }
    }
}
void power(matrix& a,int n,int MOD){
    ppp.clear();
    for(int i=0;i<k;i++){
        ppp.x[i][i]=1;
    }
    while(n>0){
        if((n&1)==1){
            mul(ppp,k,a,k,k,mm);
            ppp=tmp;
        }
        mul(a,k,a,k,k,mm);
        a=tmp;
        n>>=1;
    }
}
int main()
{
    mm=6;
    while(scanf("%d%d",&n,&k),n!=0&&k!=0){
        a.clear();
        b.clear();
        c.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                scanf("%d",&a.x[i][j]);
            }
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&b.x[i][j]);
            }
        }
        mul(b,k,a,k,n,mm);
        c=tmp;
        power(c,n*n-1,mm);
        c=ppp;
        mul(a,n,c,n,k,mm);
        c=tmp;
        mul(c,n,b,n,k,mm);
        c=tmp;
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans+=c.x[i][j];
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
