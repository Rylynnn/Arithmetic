#include <bits/stdc++.h>
#define N 1007
using namespace std;
long long x[N],y[N],z[N],n;
long long gcd(long long a,long long b){
    return (b==0)?a:gcd(b,a%b);
}
bool solve(int i,int j){
    int mn,mx,mmn,mmx,g;
    g=gcd(x[i],x[j]);
    mn=y[i]-z[j];//可以取的gcd的范围
    mx=z[i]-y[j];
    //cout<<g<<endl;
    if(g>=min(fabs(mx),fabs(mn))&&g<=max(fabs(mx),fabs(mn))){
        return true;
    }
    else if(g<min(fabs(mx),fabs(mn))){
        mmn=mn/g;
        mmx=mx/g;//cout<<mmx<<' '<<mmn;
        return mmn!=mmx;
    }
    else if(g>max(fabs(mx),fabs(mn))){
        if(0>=min(mx,mn)&&0<=max(mx,mn)){
            return true;
        }
        return false;
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF){
        int p=0;
        for(int i=0;i<n;i++){
            scanf("%I64d%I64d%I64d",&x[i],&y[i],&z[i]);
            for(int j=0;j<i;j++){//cout<<solve(i,j);
                if(solve(i,j)){
                    p=1;
                }
            }
        }
        if(p==1){
            printf("Cannot Take off\n");
        }
        else{
            printf("Can Take off\n");
        }

    }
    return 0;
}
