#include<iostream>
#include<cmath>
#include<algorithm>
#define eps 1e-6
using namespace std;
double p[10001];
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if (max(a,b)<=210)
        {
            cout<<"stupid"<<endl;
            continue;
        }
        int ans=0;
        int L=b-a+1;
        double E=0;
        for (int i=1; i<=L; i++) p[i]=1;
        double ep=0,temp=0;
        while (1)
        {
            ++ans;
            E=temp=0;
            for (int i=1; i<=L; i++) p[i]*=((i*1.0)/L);
            for (int i=b; i>=a; i--)
            {
                ep=1-p[L-(b-i+1)];
                E+=(ep-temp)*i;
                temp=ep;
            }
            if (E>=210)
            {
                cout<<ans<<endl;
                break;
            }
        }
    }
    return 0;
}
