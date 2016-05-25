#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll x,y;
}bot[100007];
struct mode{
    ll t,a,b;
}dis[100007];
ll ax,ay,bx,by,tx,ty,ans;
int vis[100007];
ll dist(int m,int n,int x,int y){
    return (x-m)*(x-m)+(y-n)*(y-n);
}
int main()
{
    int maxa,maxb,n;
    while(scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&ax,&ay,&bx,&by,&tx,&ty)!=EOF){
        scanf("%d",&n);
        ans=0;
        maxa=maxb=-1;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%I64d%I64d",&bot[i].x,&bot[i].y);
            dis[i].t=dist(bot[i].x,bot[i].y,tx,ty);
            dis[i].a=dist(bot[i].x,bot[i].y,ax,ay);
            dis[i].b=dist(bot[i].x,bot[i].y,bx,by);
        }
        for(int i=0;i<n;i++){
            if(dis[i].a<dis[i].t){
                if(dis[maxa].t+dis[maxa].a>dis[i].a+dis[i].t){
                    maxa=i;
                }
            }
            if(dis[i].b<dis[i].t){
                if(dis[maxb].t+dis[maxb].b>dis[i].t+dis[i].b){
                    maxb=i;
                }
            }
        }
        if(maxa==-1||maxb==-1){

        }
        if(maxa==maxb){
            if(dis[maxa].a<dis[maxb].b){
                vis[maxa]=1;
                for(int i=0;i<n;i++){
                    if(vis[i]!=1&&dis[i].b<dis[i].t){
                        if(dis[maxb].t>dis[i].t){
                            maxb=i;
                        }
                    }
                }
            }
            else{
                vis[maxb]=1;
                for(int i=0;i<n;i++){
                    if(vis[maxb]!=1&&dis[i].a<dis[i].t){
                        if(dis[maxa].t>dis[i].t){
                            maxa=i;
                        }
                    }
                }
            }
        }

        vis[maxa]=vis[maxb]=1;
        ans+=dis[maxa].a+dis[maxa].t+dis[maxb].b+dis[maxb].t;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                vis[i]=1;
                ans+=2*dis[i].t;
            }
        }
        cout<<ans<<endl;
    }

}
