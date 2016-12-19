#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,d,e;
    double t1,t2,t3,t4,t5;
    double m,n,s1,s2,s3,s4,s5;
    while(cin>>a>>b>>c>>d>>e){
        cin>>t1>>t2>>t3>>t4>>t5;
        cin>>m>>n;
        s1=max(0.3*500,(1-a/250)*500-50*t1);

        s2=max(0.3*1000,(1-b/250)*1000-50*t2);

        s3=max(0.3*1500,(1-c/250)*1500-50*t3);

        s4=max(0.3*2000,(1-d/250)*2000-50*t4);

        s5=max(0.3*2500,(1-e/250)*2500-50*t5);
        cout<<s1+s2+s3+s4+s5+100*m-50*n<<endl;
    }
}
