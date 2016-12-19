#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#define inf 10000000000LL
#define MAX 1000100
#define MOD 100
#define ll long long
using namespace std;
int sg[MAX];
ll dfs(int k){
    if(sg[k]!=-1){
        return sg[k];
    }
    int now;
    for(int i=1;i<=k;i*=10){
        if(k/i%10){//如果当前这个
            now=k;
            do{//do-while导致每次先剪去后手的选择，再判断先手是否能进行操作
                now-=i;
                if(now<i){
                    break;
                }
                if(!sg[now]){
                    return sg[k]=1;
                }
            }while(now/i%10);
        }
        else if(!sg[k/i/10]){//如果下一位为0
            return sg[k]=1;
        }
    }
    return sg[k]=0;
}
int main()
{
    char a[10];
    memset(sg,-1,sizeof(sg));
    sg[0]=1;
    for(int i=1;i<MAX;i++){
        dfs(i);
        //cout<<sg[i]<<' ';
    }
    while(scanf("%s",a)!=EOF){
        if(a[0]=='0'){
            printf("Yes\n");
            continue;
        }
        int sum=0;
        for(int i=0;i<strlen(a);i++){
            sum*=10;
            sum+=a[i]-'0';
        }
        if(sg[sum]==1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}

