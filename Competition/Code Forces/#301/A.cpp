/*
啊啊啊啊啊（1000位我竟然用int读真是脑浊了。。
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,num,shun,ni;
    string c,d;
    int a[1007],b[1007];
    while(scanf("%d",&n)!=EOF){
        num=0;
        cin>>c>>d;
        for(int i=0;i<c.size();i++){
            a[i]=c[i]-'0';
            b[i]=d[i]-'0';
            //cout<<a[i]<<' '<<b[i]<<' ';
        }
        for(int i=0;i<n;i++){
            shun=fabs(a[i]-b[i]);
            if(a[i]<5){
                ni=a[i]+10-b[i];
            }
            else{
                ni=10-a[i]+b[i];
            }
            //cout<<shun<<' '<<ni;
            num+=min(ni,shun);
            //cout<<num<<endl;
        }
        printf("%d\n",num);
    }
    return 0;
}
