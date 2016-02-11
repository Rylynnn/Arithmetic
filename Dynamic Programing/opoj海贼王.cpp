#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAX 1000000
#define N 20
using namespace std;
int a[N][N];
int n;
int dodp(int s,int i);
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ans=MAX;
    for(i=1;i<=n;i++){
        ans=min(ans,dodp((1<<n)-1,i-1));
    }
    printf("%d",ans);
}
int dodp(int s,int i){
    int s1,j,c;
    char num[20];
    int minm;
    if(s==(1<<i)){
        return 0;
    }
    else{
        minm=MAX;
        for(j=0;j<n;j++){
            c=(s&(1<<j))>>j;//可能当前集合没有j点
            //printf("%d ",c);
            if(c==1){
                s1=s&(~(1<<i));
                _itoa(s1,num,2);
                printf("%s\n",num);
                minm=min(minm,dodp(s1,j)+a[j][i]);
            }
            else{
                continue;
            }
        }
        //printf("%d ",minm);
        return minm;
    }
}
