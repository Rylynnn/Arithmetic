/*
 * SPOJ 694
 * 给定一个字符串，求不相同子串个数。
 * 每个子串一定是某个后缀的前缀，那么原问题等价于求所有后缀之间的不相同子串个数。
 * 总数为n*(n-1)/2,再减掉height[i]的和就是答案
 */

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN=1010;

/*
*suffix array
*倍增算法  O(n*logn)
*待排序数组长度为n,放在0~n-1中，在最后面补一个0
*build_sa( ,n+1, );//注意是n+1;
*getHeight(,n);
*例如：
*n   = 8;
*num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ };注意num最后一位为0，其他大于0
*rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]为有效值，rank[n]必定为0无效值
*sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]为有效值，sa[0]必定为n是无效值
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]为有效值
*
*/

int sa[MAXN];//SA数组，表示将S的n个后缀从小到大排序后把排好序的
             //的后缀的开头位置顺次放入SA中
int t1[MAXN],t2[MAXN],c[MAXN];//求SA数组需要的中间变量，不需要赋值
int rank[MAXN],height[MAXN];
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
    for(i=0;i<=n;i++)rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        j=sa[rank[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rank[i]]=k;
    }
}

char str[MAXN];
int s[MAXN];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int n=strlen(str);
        for(int i=0;i<=n;i++)s[i]=str[i];
        build_sa(s,n+1,128);
        getHeight(s,n);
        int ans=n*(n+1)/2;
        for(int i=1;i<=n;i++){
            cout<<sa[i];
            ans-=height[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
