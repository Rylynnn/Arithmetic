#include <cstdio>
#include <set>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int par1[5010];
set<int>h[5010];
int ran[5010];
void init(int n){
    int i;
    for(i=1;i<=n;i++){
        par1[i]=i;
        ran[i]=1;
    }
}
int findpar(int x){
    if(par1[x]==x){
        return par1[x];
    }
    else return par1[x]=findpar(par1[x]);
}
void unit1(int x,int y){
    x=findpar(x);
    y=findpar(y);
    if(x!=y){
        par1[x]=y;
    }
}
void unit2(int x,int y){
    h[x].insert(y);
    h[y].insert(x);
    return;
}
int same1(int x,int y){
    if(findpar(x)==findpar(y))return 1;
    else return 0;
}
int same2(int x,int y){
    if(h[x].find(y)!=h[x].end()&&h[y].find(x)!=h[y].end())return 1;
    else return 0;
}
int main()
{
    int n,m,k,a,b,c;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        init(n);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            if(c==1){
                unit1(a,b);
            }
            if(c==-1){
                unit2(a,b);
            }
            //cout<<a<<b<<c;
        }

        for(int i=0;i<k;i++){
            scanf("%d%d",&a,&b);
            //cout<<same1(a,b)<<same2(a,b);
            if(same1(a,b)==1&&same2(a,b)==0){
                printf("No problem\n");
            }
            else if(same1(a,b)==0&&same2(a,b)==0){
                printf("OK\n");//OK¶¼ÊÇ´óÐ´¡£¡£¡£
            }
            else if(same1(a,b)==1&&same2(a,b)==1){
                printf("OK but...\n");
            }
            else if(same1(a,b)==0&&same2(a,b)==1){
                printf("No way\n");
            }
        }
    }
    return 0;
}
