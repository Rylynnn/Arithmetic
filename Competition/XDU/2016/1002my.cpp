#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;

LL f[10000];
int num;
LL n;
LL ans,last;
int main()
{
    f[1]=1;
    f[2]=1;
    for (int i=3;;i++)
    {
        f[i]=f[i-1]+f[i-2];
        if (f[i]>1e18)
        {
            num=i;
            break;
        }
    }
    while (cin>>n)
    {
        if(n==3||n==2){
            cout<<1<<' '<<1<<endl;
        }else{
        ans=last=0;
        for (int i=1;i<=num;i++)
        {
            if (n>=ans+f[i])
            {
                ans+=f[i];
                last=f[i];
            }
            else
            {
                if (last>=n-ans)
                {
                    cout<<i-1<<" "<<last<<endl;
                    break;
                }
                else
                {
                    cout<<i<<" "<<n-ans<<endl;
                    break;
                }
            }
        }}
    }
    return 0;
}
