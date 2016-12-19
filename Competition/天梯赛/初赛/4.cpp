#include <cstdio>
#include <set>
#include <cstring>
#include <iostream>
using namespace std;
set<int>h;
int main()
{
    int n,k,a,p1,p2,m,b;
    int pp[100007];
    while(scanf("%d",&n)!=EOF){
        memset(pp,0,sizeof(pp));
        for(int i=0;i<n;i++){
            p1=0;
            scanf("%d",&k);
            if(k>1){
                p1=1;
            }
            for(int i=0;i<k;i++){
                scanf("%d",&a);
                if(p1==1){
                    h.insert(a);
                }
            }
        }
        scanf("%d",&m);
        p2=0;
        for(int i=0;i<m;i++){
            scanf("%d",&b);
            if(h.find(b)==h.end()){
                if(p2==0&&pp[b]==0){
                    pp[b]=1;
                    if(b<10000){
                        int t=b,num=0;
                        while(t){
                            t/=10;
                            num++;
                        }
                        for(int j=0;j<(5-num);j++){
                            cout<<0;
                        }
                        cout<<b;
                    }
                    else{
                        cout<<b;
                    }
                    p2=1;
                }
                else if(p2==1&&pp[b]==0){
                    pp[b]=1;
                    if(b<10000){
                        cout<<' ';
                        int t=b,num=0;
                        while(t){
                            t/=10;
                            num++;
                        }
                        for(int j=0;j<(5-num);j++){
                            cout<<0;
                        }
                        cout<<b;
                    }
                    else{
                        cout<<' '<<b;
                    }
                }
            }
        }
        if(p2==1){
            cout<<endl;
        }
        if(p2==0){
            cout<<"No one is handsome"<<endl;
        }
    }
    return 0;
}
