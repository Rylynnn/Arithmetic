#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN=100007;
int sa[MAXN];//SA数组，表示将S的n个后缀从小到大排序后把排好序的
             //的后缀的开头位置顺次放入SA中
int t1[MAXN],t2[MAXN],c[MAXN];//求SA数组需要的中间变量，不需要赋值
int ran[MAXN],height[MAXN];
//待排序的字符串放在s数组中，从s[0]到s[n-1],长度为n,且最大值小于m,
//除s[n-1]外的所有s[i]都大于0，r[n-1]=0
//函数结束以后结果放在sa数组中
void build_sa(int s[],int n,int m)
{
    int i,j,p,*x=t1,*y=t2;
    //第一轮基数排序，如果s的最大值很大，可改为快速排序
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        //直接利用sa数组排序第二关键字
        for(i=n-j;i<n;i++)y[p++]=i;//后面的j个数第二关键字为空的最小
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        //这样数组y保存的就是按照第二关键字排序的结果
        //基数排序第一关键字
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        //根据sa和x数组计算新的x数组
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n)break;
        m=p;//下次基数排序的最大值
    }
}
void getHeight(int s[],int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++)ran[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        j=sa[ran[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[ran[i]]=k;
    }
}
char str[MAXN],x[3];
int s[MAXN];
vector<int>locx;
vector<int>::iterator it;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        locx.clear();
        scanf("%s",x);
        scanf("%s",str);
        int n=strlen(str);
        for(int i=0;i<=n;i++){
            if(str[i]==x[0]){
                locx.push_back(i);
            }
        }
        for(int i=0;i<=n;i++)s[i]=str[i];
        build_sa(s,n+1,128);
        getHeight(s,n);
        long long ans=0;
        for(int i=0;i<=n;i++){
            it=lower_bound(locx.begin(),locx.end(),sa[i]);
            if(it!=locx.end()) {
                ans+=n-max(sa[i]+height[i],*it);
            }
        }
        printf("Case #%d: %I64d\n",++kase,ans);
    }
    return 0;
}
