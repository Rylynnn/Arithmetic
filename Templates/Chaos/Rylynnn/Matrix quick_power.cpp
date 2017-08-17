#include <bits/stdc++.h>
#define N 10
using namespace std;
struct matrix{
    int x[N][N];
    void clear(){
        memset(x,0,sizeof(x));
    }
}tmp,ppp,a,b,c;
int k,mm;
void mul(matrix& a,int ab,matrix& b,int bb,int tmpb,int MOD){//æÿ’Û≥À∑®
    tmp.clear();
    for(int i=0;i<ab;i++){
        for(int j=0;j<bb;j++){
            for(int k=0;k<tmpb;k++){
                tmp.x[i][j]=(tmp.x[i][j]+a.x[i][k]*b.x[k][j])%MOD;
            }
        }
    }
}
void power(matrix& a,int n,int MOD){//øÏÀŸ√›
    ppp.clear();
    for(int i=0;i<N;i++){
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
    return 0;
}
