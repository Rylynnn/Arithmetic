/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/23 22:34:04
File Name     :E:\2014ACM\专题学习\数据结构\二维树状数组\POJ2155.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 1010;
int lowbit(int x)
{
    return x&(-x);
}
int c[MAXN][MAXN];
int n;
int sum(int x,int y)
{
    int ret = 0;
    for(int i = x;i > 0;i -= lowbit(i))
        for(int j = y;j > 0;j -= lowbit(j))
            ret += c[i][j];
    return ret;
}
void add(int x,int y,int val)
{
    for(int i = x;i <= n;i += lowbit(i))
        for(int j = y;j <= n;j += lowbit(j))
            c[i][j] += val;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,j,k;
    scanf("%d",&T);
    while(T--)
    {
        int q;
        scanf("%d%d",&n,&q);
        memset(c,0,sizeof(c));
        char op[10];
        int x1,y1,x2,y2;
        while(q--)
        {
            scanf("%s",op);
            if(op[0] == 'C')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                add(x1,y1,1);
                add(x2+1,y1,1);
                add(x1,y2+1,1);
                add(x2+1,y2+1,1);
                for(j=1;j<=n;j++){
                    for(k=1;k<=n;k++){
                        printf("%d",c[j][k]);
                    }
                }
            }
            else
            {
                scanf("%d%d",&x1,&y1);
                if(sum(x1,y1)%2 == 0)printf("0\n");
                else printf("1\n");
            }
        }
        if(T > 0)printf("\n");
    }
    return 0;
}
