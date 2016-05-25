/*
ID: 15829681
LANG: C++
TASK: beads
*/
#include <cstdio>
#include <string>
#include <iostream>
#define LOCAL
using namespace std;
int main()
{
    #ifdef LOCAL
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    #endif
    int n;
    string a,b;
    scanf("%d",&n);
    cin>>a;
    b=a+a;
    int maxm=0,i,j,num,p;
    char col;
    for(i=0;i<a.size();i++){//
        col=a[i];
        num=1,p=0;
        for(j=i+1;j<i+n;j++){
            if(b[j]!='w'){
                if(col=='w'){
                    col=b[j];
                    num++;
                }
                else{
                    if(col!=b[j]){
                        if(p==0){
                            col=b[j];//忘了第一次转变之后前驱要更换。。。
                            p=1;
                            num++;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        num++;
                    }
                }
            }
            else{
                num++;
            }
            if(num>a.size()){
                num=a.size();
                break;
            }
        }
        if(num>maxm){
            maxm=num;
        }
    }
    printf("%d\n",maxm);
}
