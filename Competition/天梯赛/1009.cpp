#include <iostream>
#include <cstdio>
#include <map>
#define ll long long
using namespace std;
int a[60][10007];
map <int,int> h;
struct node{
    int num;
    int a[10007];
}se[60];
int main()
{
    int n,nn,d,m,k,b,c;
    double ans;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        h.erase(h.begin(),h.end());
        nn=0;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d",&d);
            if(h[d]==0){
                se[i].a[nn++]=d;
                h[d]=1;
            }
        }
        se[i].num=nn;
        sort(se[i].a,se[i].a+nn);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        double nc=0,nt=0;
        scanf("%d%d",&b,&c);
        for(int i=0;i<se[b-1].num;i++){
            h[se[b-1].a[i]]=1;
        }
        for(int i=0;i<se[c-1].num;i++){
            if(h[se[c-1].a[i]]==1){
                nc++;
            }
        }
        nt=se[c-1].num+se[b-1].num-nc;
        ans=nc*100/nt;
        printf("%.2f%%\n",ans);
    }
    return 0;
}
