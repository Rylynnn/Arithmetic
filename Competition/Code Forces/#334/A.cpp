#include <bits/stdc++.h>
using namespace std;
int main()
{
    double m1,m2,m3,m4,m5;
    double w1,w2,w3,w4,w5;
    double hs,hu;
    double s1,s2,s3,s4,s5;
    double ans;
    while(cin>>m1>>m2>>m3>>m4>>m5){
        ans=0;
        cin>>w1>>w2>>w3>>w4>>w5;
        cin>>hs>>hu;
        s1=max(0.3*500,(1-m1/250)*500-50*w1);
        s2=max(0.3*1000,(1-m2/250)*1000-50*w2);
        s3=max(0.3*1500,(1-m3/250)*1500-50*w3);
        s4=max(0.3*2000,(1-m4/250)*2000-50*w4);
        s5=max(0.3*2500,(1-m5/250)*2500-50*w5);
    //cout<<s1<<s2<<s3<<s4<<s5;
        ans=s1+s2+s3+s4+s5+hs*100-hu*50;
        cout<<ans<<endl;
    }
    return 0;
}
