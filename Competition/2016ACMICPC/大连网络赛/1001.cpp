#include <bits/stdc++.h>
#define eps 1e-6
#define MOD 1000000007
#define N 100007
#define ll long long
using namespace std;
int prime[N],phi[N],cnt,fib[N];// prime:记录质数，phi记录欧拉函数
int Min_factor[N];// i的最小素因子
bool vis[N];
int getFib(int n){   // 求 (t^n)%MOD
    int t[2][2] = {1, 1, 1, 0};
    int ans[2][2] = {1, 0, 0, 1};  // 初始化为单位矩阵
    int tmp[2][2];    //自始至终都作为矩阵乘法中的中间变量

    while(n){
        if(n & 1)  //实现 ans *= t; 其中要先把 ans赋值给 tmp，然后用 ans = tmp * t
            {
            for(int i = 0; i < 2; ++i)
                for(int j = 0; j < 2; ++j)
                    tmp[i][j] = ans[i][j];
            ans[0][0] = ans[1][1] = ans[0][1] = ans[1][0] = 0;  // 注意这里要都赋值成 0

            for(int i = 0; i < 2; ++i){
                for(int j = 0; j < 2; ++j){
                    for(int k = 0; k < 2; ++k)
                        ans[i][j] = (ans[i][j] + tmp[i][k] * t[k][j]) % MOD;
                }
            }
        }

        //  下边要实现  t *= t 的操作，同样要先将t赋值给中间变量  tmp ，t清零，之后 t = tmp* tmp
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)
                tmp[i][j] = t[i][j];
        t[0][0] = t[1][1] = 0;
        t[0][1] = t[1][0] = 0;
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                for(int k = 0; k < 2; ++k)
                    t[i][j] = (t[i][j] + tmp[i][k] * tmp[k][j]) % MOD;
            }
        }

        n >>= 1;
    }
    return ans[0][1];
}
void IInit()
{
    cnt=0;
    phi[1]=1;
    int x;
    for(int i=2;i<N;i++)  {
        if(!vis[i])  {
            prime[++cnt]=i;
            phi[i]=i-1;
            Min_factor[i]=i;
        }
        for(int k=1;k<=cnt&&prime[k]*i<N;k++)  {
            x=prime[k]*i;
            vis[x]=true;
            Min_factor[x]=prime[k];
            if(i%prime[k]==0){
                phi[x]=phi[i]*prime[k];
                break;
            }
            else phi[x]=phi[i]*(prime[k]-1);
        }
    }
}
int mul_mod(int a,int b,int m){
    int ans=0;
    a%=m;
    while(b>0){
        if(b&1){
            ans+=a;
            ans%=m;
        }
        b=b>>1;
        a+=a;
        a%=m;
    }
    return ans;
}
int pow_mod(int a,int b,int m){
    int ans=1;
    a%=m;
    while(b>0){
        if(b&1){
            ans=mul_mod(ans,a,m)%m;
        }
        b=b>>1;
        a=mul_mod(a,a,m)%m;
    }
    return ans;
}
int mul(int i,int n){
    int temp=phi[n/i];
    temp=((long long)temp*(long long)(getFib(i-1)+getFib(i+1)))%MOD;
    return temp;
}
int main()
{
    int n,now;
    IInit();
    while(scanf("%d",&n)!=EOF){
        if(n==1) {
			cout<<2<<endl;
			continue;
		}
        ll ans=pow_mod(n,MOD-2,MOD),sum=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                sum+=mul(i,n);
                sum%=MOD;
            }
            if (i*i!=n){
				sum+=mul(n/i,n);
				sum%=MOD;
            }
            cout<<sum<<' ';
        }
        cout<<ans<<' ';
        ans=(sum*ans)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
