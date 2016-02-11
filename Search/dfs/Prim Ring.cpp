#include<cstdio>
int a[25];
int n,k;
void dfs(int a[],int t);
void print(int a[]);
bool judge(int a[],int last,int next);
bool prime(int n){
    if((n==2)||(n==3)||(n==5)||(n==7)||(n==11)||(n==13)||(n==17)||(n==19)||(n==23)||(n==29)||(n==31))return true;
    else return false;
}
int main()
{
    k=1;
    while(scanf("%d",&n)!=EOF){
        a[0]=1;
        printf("Case %d:\n",k++);
        dfs(a,1);
        printf("\n");
    }
    return 0;
}
void print(int a[]){
    for(int i=0;i<n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n-1]);
}
bool judge(int a[],int last,int next){
    if(last-1<0)return true;
    for(int i=0;i<last;i++){//去重
        if(a[i]==next)return false;
    }
    if(!((a[last-1]+next)&1))return false;//如果相邻为偶数
    if(!prime(a[last-1]+next))return false;//如果相邻不是素数
    return true;
}
void dfs(int a[],int t){
    if(n&1)return;
    if(t==n&&prime(a[0]+a[t-1])){
        print(a);
        return;
    }
    for(int i=2;i<=n;i++){
        a[t]=i;
        if(judge(a,t,i))dfs(a,t+1);
    }
}
