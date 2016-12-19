#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
long long mod = 1000000007LL;
int main(){
    vector<vector<int> > left,right,up,down;
    vector<vector<int> > grid;
    vector<vector<long double> > l,r,u,d;
    int n;
    cin>>n;
    grid.assign(n+10,vector<int>(n+10,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            grid[i][j]=(int)(c-'0');
        }
    }
    left.assign(n+10,vector<int>(n+10,0));
    right=up=down=left;
    l.assign(n+10,vector<long double>(n+10,(double)0.0));
    r=u=d=l;
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<grid[i][j]<<endl;
        }
    }*/
    vector<long double> lg(10,0.0);
    for(int i=1;i<10;i++){
        lg[i]=(long double)log((long double)i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]!=0){
                left[i][j]=left[i][j-1]+1;
            }
            l[i][j]=l[i][j-1]+lg[grid[i][j]];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=n;j>=1;j--){
            if(grid[i][j]!=0){
                right[i][j]=right[i][j+1]+1;
            }
            r[i][j]=r[i][j+1]+lg[grid[i][j]];

        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(grid[i][j]!=0){
                up[i][j]=up[i-1][j]+1;
            }
            u[i][j]=u[i-1][j]+lg[grid[i][j]];
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=n;i>=1;i--){
            if(grid[i][j]!=0){
                down[i][j]=down[i+1][j]+1;
            }
            d[i][j]=d[i+1][j]+lg[grid[i][j]];
        }
    }

    long double ans=-1.0;
    int pr=1,pc=1,pd=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(grid[i][j]==0) continue;
            int d = min(min(up[i][j],down[i][j]),min(left[i][j],right[i][j]));
            long double temp = u[i+d-1][j]-u[i-d][j]+l[i][j+d-1]-l[i][j-d]-lg[grid[i][j]];
            if(ans-temp<0){
                ans=temp;
                pr=i;
                pc=j;
                pd=d;
            }
        }
    }
    long long a=1LL;
    for(int i=1;i<pd;i++){
        a=(a*(long long)grid[pr][pc-i])%mod;
        a=(a*(long long)grid[pr][pc+i])%mod;
        a=(a*(long long)grid[pr+i][pc])%mod;
        a=(a*(long long)grid[pr-i][pc])%mod;
    }
    a=(a*(long long)grid[pr][pc])%mod;

    up.assign(n+10,vector<int>(n+10,0));
    down = left = right = up;
    l.assign(n+10,vector<long double>(n+10,0.0));
    r=u=d=l;

    for(int lvl = 2;lvl<=2*n;lvl++){
        for(int i=max(1,lvl-n);i<=min(n,lvl-1);i++){
            int j = lvl-i;
            if(grid[i][j]!=0){
                up[i][j]=up[i-1][j-1]+1;
                right[i][j]=right[i-1][j+1]+1;
            }
            r[i][j]=r[i-1][j+1]+lg[grid[i][j]];
            u[i][j]=u[i-1][j-1]+lg[grid[i][j]];
        }
    }
    for(int lvl=2*n;lvl>=2;lvl--){
        for(int i=min(n,lvl-1);i>=max(1,lvl-n);i--){
            int j= lvl-i;
            if(grid[i][j]!=0){
                left[i][j]=left[i+1][j-1]+1;
                down[i][j]=down[i+1][j+1]+1;
            }
            l[i][j]=l[i+1][j-1]+lg[grid[i][j]];
            d[i][j]=d[i+1][j+1]+lg[grid[i][j]];
        }
    }
    double ans2=-1.0;
    for(int lvl = 2;lvl<=2*n;lvl++){
        for(int i=max(1,lvl-n);i<=min(n,lvl-1);i++){
            int j =lvl-i;
            int d = min(min(up[i][j],down[i][j]),min(left[i][j],right[i][j]));
            long double temp = u[i+d-1][j+d-1]-u[i-d][j-d]+r[i+d-1][j-d+1]-r[i-d][j+d]-lg[grid[i][j]];
            if(ans2-temp<0){
                ans2=temp;
                pr=lvl;
                pc=i;
                pd=d;
            }
        }
    }
    long long b=1LL;
    for(int i=1;i<pd;i++){
        b=(b*(long long)grid[pc+i][pr-pc+i])%mod;
        b=(b*(long long)grid[pc+i][pr-pc-i])%mod;
        b=(b*(long long)grid[pc-i][pr-pc-i])%mod;
        b=(b*(long long)grid[pc-i][pr-pc+i])%mod;
    }
    b=(b*(long long)grid[pc][pr-pc])%mod;
    if(ans2>ans) a=b;
    cout<<a<<endl;
    return 0;
}
