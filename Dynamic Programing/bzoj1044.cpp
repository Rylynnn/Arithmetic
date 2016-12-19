#include <cstdio>
using namespace std;
int sum,n,m,ssum[];
bool check(int ans)
{
    int now=0,tmp=0;
    for(int i=0; i<n; i++){
        if(now+a[i]<=ans){
            now+=a[i];
        }
        else{
            if(a[i]>ans||t>=m){
                return false;
            }
            t++;
            now=a[i];
        }
    }
    return ture;
}
int maxm(int l,int r){
    if(l==r){
        return 1;
    }
    int mid=(l+r)/2;
    if(check(mid)){
        return maxm(l,mid);
    }
    else{
        return maxm(mid+1,r);
    }
int main(){
    int n;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0; i<n; i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        ssum[0]=a[0];
        for(int i=0; i<n; i++){
            ssum[i]=ssum[i-1]+a[i];
        }
        ans=maxm(1,sum);
        for(int i=0
