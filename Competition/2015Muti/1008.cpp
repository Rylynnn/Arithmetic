#include<cstdio>
#include<queue>
#include<cstring>

#include<algorithm>
#define N 100010
#define M 0x7fffffff
using namespace std;
typedef struct node{
    int l;
    int r;
    int num;
    friend bool operator < (node a,node b){
        return a.r>b.r;
    }
}soda;
soda s[N];
int n;
int p[N];
priority_queue<soda,vector<soda>,less<soda> >q;
bool cmp(soda a,soda b){
    if(a.l!=b.l){
        return a.l<b.l;
    }
    else{
        if(a.r!=b.r){
            return a.r<b.r;
        }
    }
}
int main()
{
    //freopen("in,txt","r",stdin);
    int t,i;
    int ans[N],no[N];
    while(scanf("%d",&t)!=EOF){
        while(t--){
            scanf("%d",&n);
            memset(p,0,sizeof(p));
            memset(ans,0,sizeof(ans));
            for(i=1;i<=n;i++){
                scanf("%d",&s[i].l);
                s[i].num=i;
            }
            int cnt=0;
            for(i=1;i<=n;i++){
                scanf("%d",&s[i].r);
            }
            sort(s+1,s+n+1,cmp);
            i=1;
            while(1){
                while(i<=n&&s[i].l<=cnt){
                    q.push(s[i]);
                    //printf("%d ",s[i].l);
                    i++;
                }
                //printf("\n");
                while(!q.empty()&&q.top().r<cnt){
                    q.pop();
                }
                if(q.empty()){
                    break;
                }
                //now=q.top();
                ans[cnt++]=q.top().num;
                //printf("%d\n",q.top().r);
                p[q.top().num]=1;
                q.pop();
            }
            printf("%d\n",cnt);
            for(i=1;i<=n;i++){
                if(p[i]==0){
                    ans[cnt++]=i;
                }
            }
            printf("%d",ans[0]);
            for(i=1;i<n;i++){
                printf(" %d",ans[i]);
            }
            printf("\n");
        }
    }

}
