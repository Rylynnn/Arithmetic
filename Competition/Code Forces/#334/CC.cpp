#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,p,n0,num;
    string a;
    while(scanf("%d",&n)!=EOF){
        cin>>a;
        int n0=0;
        if(a[0]=='0'){
            num=1;
            p=0;
            n0=1;
        }
        else{
            num=1;
            p=1;
        }
        for(int i=1;i<a.size();i++){
            if(p==0&&a[i]=='1'){
                maxm=max(maxm,n0);
                num++;
                p=1;
            }
            else if(p==1&&a[i]=='0'){
                num++;
                n0=1;
                p=0;
            }
            else if(p==0&&a[i]=='0'){
                n0++;
            }
        }
        if(maxm>2){
            printf("%d\n",num+1);
        }
        else{
            printf("%d\n",num);
        }
    }
    return 0;
}
