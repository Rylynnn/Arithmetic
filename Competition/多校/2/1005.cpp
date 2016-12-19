#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const long long MOD=1e9+7;

struct Point {
    long long x,y;
    bool operator < (const Point& a) const {
        return x<a.x||(x==a.x&&y<a.y);
    }
}p[1005];

struct Node {
    long long dx,dy;
    Point a,b;

    bool operator < (const Node& a) const {
        if(dx==0)
            return false;
        if(a.dx==0)
            return true;
        return dy*a.dx<a.dy*dx;
    }

    bool operator == (const Node& a) const {
        if(dx==0)
            return a.dx==0;
        if(a.dx==0)
            return false;
        return dy*a.dx==a.dy*dx;
    }

    void makeLine(const Point& aa,const Point& bb) {
        a=aa;
        b=bb;
        dx=a.x-b.x;
        dy=a.y-b.y;
        if(dx<0) {
            dx=-dx;
            dy=-dy;
        }
    }
}line[1000005];

int n,tot,num,t;
long long ans,cnt,tmp;
map<Point,int> mp;
map<Point,bool> vis;

long long quickpow(long long m,long long n) {
    long long b = 1;
    while (n > 0) {
        if (n & 1)
            b = (b*m)%MOD;
        n = n >> 1 ;
        m = (m*m)%MOD;
    }
    return b;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T-->0) {
        mp.clear();
        tot=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i) {
            scanf("%I64d%I64d",&p[tot].x,&p[tot].y);
            ++mp[p[tot]];
            if(mp[p[tot]]==1) {
                ++tot;
            }
        }
        ans=num=0;
        for(int i=0;i<tot;++i) {
            for(int j=i+1;j<tot;++j) {
                line[num++].makeLine(p[i],p[j]);
            }
        }
        sort(line,line+num);
        cnt=1;
        for(int i=1;i<num;++i) {
            if(line[i]==line[i-1]) {
                ++cnt;//统计平行线段的个数
            }
            else {
                t=cnt;
                tmp=0;
                vis.clear();
                while(t>0) {
                    if(!vis[line[i-t].a]) {
                        tmp+=mp[line[i-t].a]-1;
                        vis[line[i-t].a]=true;
                    }
                    if(!vis[line[i-t].b]) {
                        tmp+=mp[line[i-t].b]-1;
                        vis[line[i-t].b]=true;
                    }
                    --t;
                }
                cnt=(1+sqrt(1.0+8*cnt))/2+0.000001+tmp;//计算共线的点的个数
                ans=(ans+quickpow(2,cnt)-1-cnt+MOD)%MOD;//这些平行线段中互相匹配的结果
                cnt=1;
            }
        }
        if(num>0) {
            t=cnt;
            tmp=0;
            vis.clear();
            while(t>0) {
                if(!vis[line[num-t].a]) {
                    tmp+=mp[line[num-t].a]-1;
                    vis[line[num-t].a]=true;
                }
                if(!vis[line[num-t].b]) {
                    tmp+=mp[line[num-t].b]-1;
                    vis[line[num-t].b]=true;
                }
                --t;
            }
            cnt=(1.0+sqrt(1.0+8*cnt))/2+0.000001+tmp;//计算共线的点的个数
            ans=(ans+quickpow(2,cnt)-1-cnt+MOD)%MOD;
        }
        else if(n>1) {
            ans=(quickpow(2.0,n)-1-n+MOD)%MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
