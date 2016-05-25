#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,q,ans,mx,mx_r,mx_c,cnt;
int g[7][7];
bool isDouble;

bool isOK(int r,int c) {
    cnt=0;
    isDouble=false;
    for(int i=0;i<r;++i) {
        if(g[i][c]==2) {
            if(cnt==1) {
                cnt=2;
                isDouble=true;
            }
            else {
                cnt=1;
                isDouble=false;
            }
        }
        else if(g[i][c]==1&&cnt!=0) {
            if(isDouble){
                isDouble=false;
            }
            else {
                ++cnt;
            }
        }
    }
    if(cnt==2) {
        return false;
    }
    cnt=0;
    isDouble=false;
    for(int j=0;j<c;++j) {
        if(g[r][j]==2) {
            if(cnt==1) {
                cnt=2;
                isDouble=true;
            }
            else {
                cnt=1;
                isDouble=false;
            }
        }
        else if(g[r][j]==1&&cnt!=0) {
            if(isDouble) {
                isDouble=false;
            }
            else {
                ++cnt;
            }
        }
    }
    if(cnt==2) {
        return false;
    }
    return true;
}

void dfs(int r,int num) {
    if(r==n) {
        if(num>ans) {
            ans=num;
        }
        return ;
    }
    for(int c=0;c<m;++c) {
        if(g[r][c]==0&&isOK(r,c)) {
            g[r][c]=2;
            dfs(r+1,num+1);
            for(int j=c+1;j<m;++j) {
                if(g[r][j]==0&&isOK(r,j)) {
                    g[r][j]=2;
                    dfs(r+1,num+2);
                    g[r][j]=0;
                }
            }
            g[r][c]=0;
        }
    }
}

int main() {
    int r,c;
    while(3==scanf("%d%d%d",&n,&m,&q)) {
        memset(g,0,sizeof(g));
        ans=mx_r=mx_c=0;
        while(q-->0) {
            scanf("%d%d",&r,&c);
            g[r][c]=1;
        }
        for(int i=0;i<n;++i) {
            dfs(i,0);
        }
        printf("%d\n",ans);
    }
}
